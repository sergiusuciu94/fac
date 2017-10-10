import java.util.ArrayList;

public class main {

    public static void main(String[] argc) {
        ArrayList <CustomThread> ar = new ArrayList<>();
        int[][] m1 = new int[10][10];
        int[][] m2 = new int[10][10];

        Matrice output = new Matrice();


        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < 10;j++) {
                m1[i][j] = (int)(Math.random() * 100);
                m2[i][j] = (int)(Math.random() * 100);
            }
        }


        for (int i = 0; i < 4; i++) {
            CustomThread ct = new CustomThread(i, m1, m2, output);

            ar.add(ct);
        }

        for (int i = 0; i < 4; i++) {
            ar.get(i).start();
        }

        for (int i = 0; i < 4; i++) {
            try {
                ar.get(i).join();
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        }

        output.afisare();
    }
}
