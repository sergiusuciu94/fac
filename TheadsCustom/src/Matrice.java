public class Matrice {

    int mat[][] = new int[10][10];



    void afisare() {
        for(int i = 0; i < 10; i++) {
            for (int j = 0; j < 10; j++) {
                System.out.format("%6d", mat[i][j]);
            }
            System.out.println();
        }
    }
}
