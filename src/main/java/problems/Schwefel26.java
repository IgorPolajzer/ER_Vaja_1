package problems;

import java.util.ArrayList;

public class Schwefel26 extends Problem {

    public Schwefel26() {
        setName("Schwefel26");
        setLowerBound(-500.0);
        setUpperBound(500.0);
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
