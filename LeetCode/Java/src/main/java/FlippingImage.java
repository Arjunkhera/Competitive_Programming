import java.util.Arrays;

public class FlippingImage {
    public int[][] flipAndInvertImage(int[][] A) {
        for(int[] row : A) {
            int length = row.length;
            for(int i = 0; i < (length + 1) / 2; i++) {
                int temp = row[i] ^ 1;
                row[i] = row[length - 1 - i] ^ 1;
                row[length - 1 - i] = temp;
            }
        }

        return A;
    }
}
