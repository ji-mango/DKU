package assignment1;
import java.math.BigInteger;
import java.util.*;

public class Calculator {
    public static void main(String[] args) throws Exception {
        int p = 37;                                 //p 초기화
        int[] Z = new int[p-1];                     //[Zp*,*mod p]초기화
        for(int i=1;i<p;i++) {
            Z[i-1] = i;
        }
        int[] inverse = Z.clone();                  //곱셈역원 배열
        int[] order = new int[p-1];                 //위수 배열
        List<Integer> primitiveE = new ArrayList<Integer>();   //윈시원소 배열(몇개인지 모르므로 ArrayList로 초기화)
        BigInteger modulus = BigInteger.valueOf(p); //modulus에 p값 저장

        //역원 구하기
        for(int i=0;i<p-1;i++) {                    //p와 서로소인 원소만 남겨두고 모두 -1로
            int q, r;
            int b = Z[i];
            int a = p;
            while(true) {
                q = a/b;
                r = a%b;
                if(r==0)
                    break;
                a = b;
                b = r;
            }
            if(b==1) {                              //서로소일 경우 continue
                continue;
            }
            else {                                  //서로소가 아닐경우 배열값을 -1로 바꿔줌(역원이 없음을 뜻함)
                inverse[i] = -1;
            }
        }

        for(int i=0;i<p-1;i++) {                    //-1이 아닌 원소의 역원 구하는 반복문
            if(inverse[i] == -1)
                continue;
            for(int j=1;j<p;j++) {
                if( (inverse[i]*j)%p == 1) {        //곱해서 p로 나눈 나머지가 1일 경우(역원일 경우)
                    inverse[i] = j;                 //배열에 역원값 넣기
                    break;
                }
            }
        }

        //위수, 원시원소 구하기
        for(int i=0;i<p-1;i++) {
            BigInteger num1 = BigInteger.valueOf(i+1);
            for(int j=1;j<p;j++) {
                BigInteger num2 = BigInteger.valueOf(j);
                BigInteger orderNum = num1.modPow(num2, modulus);
                if (orderNum.intValue() == 1) {     //제곱해서 mod p가 1일 경우
                    order[i] = j;                   //위수값으로 저장
                    if(j==(p-1)) {                  //그룹위수 = 원소의 위수일 경우
                        primitiveE.add(i + 1);      //원시원소 배열에 추가
                    }
                    break;
                }
            }
        }

        System.out.println();
        for(int i=0;i<p-1;i++)                      //각 원소의 역원, 위수 값 출력
            System.out.printf("%-2d - inverse: %-5d  order: %d \n", Z[i], inverse[i], order[i]);

        System.out.print("원시원소 : "+primitiveE);   //원시원소값 출력
    }
}
