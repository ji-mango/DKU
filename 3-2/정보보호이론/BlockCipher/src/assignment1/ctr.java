package assignment1;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.nio.charset.StandardCharsets;
import java.security.SecureRandom;
import javax.crypto.Cipher;
import javax.crypto.KeyGenerator;
import javax.crypto.SecretKey;
import javax.crypto.spec.IvParameterSpec;

public class ctr {
    public static void main(String[] args) throws Exception {
        KeyGenerator keyGenerator = KeyGenerator.getInstance("AES");
        keyGenerator.init(new SecureRandom());
        SecretKey secretKey = keyGenerator.generateKey();

        byte[] ivBytes = new byte[]
                {0x00, 0x01, 0x02, 0x03, 0x00, 0x00, 0x00, 0x01, 0x00, 0x01, 0x02, 0x03, 0x00, 0x00, 0x00, 0x01};   //Nonce 생성
        IvParameterSpec ivSpec = new IvParameterSpec(ivBytes);
        Cipher cipher = Cipher.getInstance("AES/CTR/NoPadding");

        //복호화
        FileInputStream inFile = new FileInputStream("jimin.bmp");
        FileOutputStream outFile1 = new FileOutputStream("ctr암호화 jimin.bmp");   //암호화 파일 생성

        byte[] input = new byte[64];
        int bytesRead;
        cipher.init(Cipher.ENCRYPT_MODE, secretKey, ivSpec);    //암호화
        while ((bytesRead = inFile.read(input)) != -1) {
            byte[] output = cipher.update(input, 0, bytesRead);
            if(output != null)
                outFile1.write(output);
        }
        byte[] output = cipher.doFinal();
        if(output != null)
            outFile1.write(output);
        inFile.close();
        outFile1.flush();
        outFile1.close();

        //복호화
        FileInputStream inFile2 = new FileInputStream("ctr암호화 jimin.bmp");
        FileOutputStream outFile2 = new FileOutputStream("ctr복호화 jimin.bmp");  //복호화 파일 생성

        byte[] input2 = new byte[64];
        int bytesRead2;
        cipher.init(Cipher.DECRYPT_MODE, secretKey, ivSpec);        //복호화
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
