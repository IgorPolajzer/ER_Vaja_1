package problems;

import java.util.ArrayList;

public class Levy extends Problem {

    public Levy() {
        setName("Levy");
        setLowerBound(-10.0);
        setUpperBound(10.0);
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
