
public class CustomThread extends Thread{

    private int id;
    private Matrice output;
    private int[][] m1;
    private int[][] m2;

    CustomThread(int id, int m1[][], int m2[][], Matrice output) {
        this.id = id;
        this.output = output;
        this.m1 = m1;
        this.m2 = m2;
    }

    @Override
    public void run() {
        super.run();

        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < 10; j++){
                output.mat[i][j] = m1[i][j] + m2[i][j];
            }
        }
    }
}
