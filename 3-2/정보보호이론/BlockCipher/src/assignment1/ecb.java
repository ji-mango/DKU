package assignment1;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.nio.charset.StandardCharsets;
import java.security.SecureRandom;
import javax.crypto.Cipher;
import javax.crypto.KeyGenerator;
import javax.crypto.SecretKey;

public class ecb {
    public static void main(String[] args) throws Exception {
        KeyGenerator keyGenerator = KeyGenerator.getInstance("DES");
        keyGenerator.init(new SecureRandom());
        SecretKey secretKey = keyGenerator.generateKey();

        Cipher cipher = Cipher.getInstance("DES/ECB/PKCS5Padding");

        //암호화
        FileInputStream inFile = new FileInputStream("jimin.bmp");
        FileOutputStream outFile = new FileOutputStream("ecb암호화 jimin.bmp");   //암호화 파일 생성

        byte[] input = new byte[64];
        int bytesRead;
        cipher.init(Cipher.ENCRYPT_MODE, secretKey);        //암호화
        while ((bytesRead = inFile.read(input)) != -1) {
            byte[] output = cipher.update(input, 0, bytesRead);
            if(output != null)
                outFile.write(output);
        }
        byte[] output = cipher.doFinal();
        if(output != null)
            outFile.write(output);
        inFile.close();
        outFile.flush();
        outFile.close();

        //복호화
        FileInputStream inFile2 = new FileInputStream("ecb암호화 jimin.bmp");
        FileOutputStream outFile2 = new FileOutputStream("ecb복호화 jimin.bmp");  //복호화 파일 생성

        byte[] input2 = new byte[64];
        int bytesRead2;
        cipher.init(Cipher.DECRYPT_MODE, secretKey);        //복호화
        while ((bytesRead2 = inFile2.read(input2)) != -1) {
            byte[] output2 = cipher.update(input2, 0, bytesRead2);
            if(output2 != null)
                outFile2.write(output2);
        }
        byte[] output2 = cipher.doFinal();
        if(output2 != null)
            outFile2.write(output2);
        inFile2.close();
        outFile2.flush();
        outFile2.close();
    }
}