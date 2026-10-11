package problems;

import java.util.ArrayList;

public class StyblinskiTang extends Problem {

    public StyblinskiTang() {
        setName("StyblinskiTang");
        setLowerBound(-5.0);
        setUpperBound(5.0);
    }

    @Override
    public double evaluate(ArrayList<Double> x_star) {
        return 0;
    }

    @Override
    int generateRandomSolution() {
        return 0;
    }
}
