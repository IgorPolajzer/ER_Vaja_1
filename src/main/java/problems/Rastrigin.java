package problems;

import java.util.ArrayList;

public class Rastrigin extends Problem {

    public Rastrigin() {
        setName("Rastrigin");
        setLowerBound(-5.12);
        setUpperBound(5.12);
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
