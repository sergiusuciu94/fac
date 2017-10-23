package sample;

public class Matrix {

    public Matrix(int rows, int collumns) {
        this.rows = rows;
        this.collumns = collumns;
        this.mat = new int[rows][collumns];
    }

    private int rows;
    public int mat[][];
    private int collumns;

    void show() {
        for(int i = 0; i < rows; i++) {
            for (int j = 0; j < collumns; j++) {
                System.out.format("%6d", mat[i][j]);
            }
            System.out.println();
        }
    }

    public int getRows() {
        return rows;
    }


    public  int getCollumns() {
        return collumns;
    }

    public void populate() {
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < collumns; j++) {
                mat[i][j] = (int)(Math.random() * 10);
            }
        }
    }

    public int get(int row, int collumn) {
        return mat[row][collumn];
    }

    public void set(int row, int collumn, int value) {
        mat[row][collumn] = value;
    }



}
