package sample;

import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;
import java.util.concurrent.TimeUnit;

public class Main {




    public static void main(String[] args) {
        Matrix m1 = new Matrix(10000, 1000);
        Matrix m2 = new Matrix(1000, 1000);
        Matrix m3 = new Matrix(10000, 1000);

        m1.populate();
        m2.populate();
        ExecutorService executor = Executors.newCachedThreadPool();
        long stopTime = 0;
        long startTime = System.currentTimeMillis();
        for (int i = 0; i < m3.getRows(); i++) {
            for (int j = 0; j < m3.getCollumns(); j++) {
                final int row = i, col = j;
                executor.submit(() -> multiply(m1, m2, m3, row, col));
            }
        }
        executor.shutdown();
        try {
            executor.awaitTermination(Long.MAX_VALUE, TimeUnit.DAYS);
            stopTime = System.currentTimeMillis();
        } catch (InterruptedException e) {
            e.printStackTrace();
        }

        long elapsedTime = stopTime - startTime;
        System.out.println(elapsedTime);
        //m3.show();


    }

    static void multiply(Matrix A, Matrix B, Matrix C, int row, int col) {
            int sum = 0;
            for (int r = 0; r < B.getRows(); r++)
                sum += A.get(row, r) * B.get(r, col);
            C.set(row, col, sum);
        }


}
