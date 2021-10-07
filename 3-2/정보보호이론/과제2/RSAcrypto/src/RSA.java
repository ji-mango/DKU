import javax.crypto.Cipher;
import javax.crypto.KeyGenerator;
import javax.crypto.SecretKey;
import javax.crypto.spec.SecretKeySpec;
import java.io.ByteArrayOutputStream;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.math.BigInteger;
import java.security.KeyFactory;
import java.security.SecureRandom;
import java.security.interfaces.RSAPrivateKey;
import java.security.interfaces.RSAPublicKey;
import java.security.spec.RSAPrivateKeySpec;
import java.security.spec.RSAPublicKeySpec;

public class RSA {
    public static void main(String[] args) throws Exception {

        BigInteger p, q, pMinus1, qMinus1, phi, d, n;
        BigInteger e = BigInteger.valueOf(65537);
        int certainty = 200;
        SecureRandom rand = SecureRandom.getInstance("SHA1PRNG");
        do{
            p = new BigInteger(1024, certainty, rand);
            pMinus1 = p.subtract(BigInteger.ONE);
        } while (!(pMinus1.gcd(e).equals(BigInteger.ONE)));         //e와 p-1이 서로소가 맞는지 확인

        do{
            q = new BigInteger(1024, certainty, rand);
            qMinus1 = q.subtract(BigInteger.ONE);
        }while (!(qMinus1.gcd(e).equals(BigInteger.ONE)));          //e와 q-1이 서로소가 맞는지 확인

        phi = pMinus1.multiply(qMinus1);
        n = p.multiply(q);
        d = e.modInverse(phi);

        System.out.println("p = "+p.toString());
        System.out.println("q = "+q.toString());
        System.out.println("n = "+n.toString());
        System.out.println("e = "+e.toString());
        System.out.println("d = "+d.toString());


        //암호화
        KeyGenerator generator = KeyGenerator.getInstance("AES");
        generator.init(128);
        SecretKey K = generator.generateKey();                      //대칭키 생성

        byte[] input = "32191105 김지민".getBytes();
        Cipher aesCipher = Cipher.getInstance("AES");
        aesCipher.init(Cipher.ENCRYPT_MODE, K);
        byte[] byteCypherText = aesCipher.doFinal(input);           //평문을 대칭키로 암호화

        KeyFactory keyFactory = KeyFactory.getInstance("RSA");      //e(keySpec)을 pubKey, privKey(keyObject)로 변환
        RSAPublicKeySpec pubKeySpec = new RSAPublicKeySpec(n, e);
        RSAPrivateKeySpec privKeySpec = new RSAPrivateKeySpec(n, d);
        RSAPublicKey pubKey = (RSAPublicKey) keyFactory.generatePublic(pubKeySpec);
        RSAPrivateKey privKey = (RSAPrivateKey) keyFactory.generatePrivate(privKeySpec);

        byte[] byteK = K.getEncoded();                              //암호화를 위해 대칭키 K를 byte로 변환
        Cipher rsaCipher = Cipher.getInstance("RSA");
        rsaCipher.init(Cipher.ENCRYPT_MODE, pubKey);

        FileOutputStream writeFile = new FileOutputStream("암호화한 K");  // 암호화한 대칭키 K를 파일로 저장
        writeFile.write(rsaCipher.doFinal(byteK));
        writeFile.close();


        //복호화
        FileInputStream bringFile = new FileInputStream("암호화한 K");    // 파일에 저장한 암호화 대칭키 불러들이기
        ByteArrayOutputStream byteBringFile = new ByteArrayOutputStream();
        int theByte = 0;
        while ((theByte = bringFile.read()) != -1) {
            byteBringFile.write(theByte);
        }
        bringFile.close();
        byte[] encodedKey = byteBringFile.toByteArray();
        byteBringFile.close();


        rsaCipher.init(Cipher.DECRYPT_MODE, privKey);                         // 대칭키를 개인키로 복호화
        byte[] decodedKey = rsaCipher.doFinal(encodedKey);
        SecretKeySpec KSpec = new SecretKeySpec(decodedKey, "AES");

        aesCipher.init(Cipher.DECRYPT_MODE, KSpec);                           // 평문을 대칭키로 복호화
        byte[] result = aesCipher.doFinal(byteCypherText);

        String string1 = new String(result);                                  // byte 형인 평문 string 으로 변환
        String string2 = new String(byteCypherText);                          // byte 형인 암호화 평문 string 으로 변환
        String string3 = new String(input);                                   // byte 형인 복호화 평문 string 으로 변환환

       System.out.println("평문: " + string1);
        System.out.println("암호화한 평문 : " + string2);
        System.out.println("복호화한 평문 : " + string3);
    }
}
