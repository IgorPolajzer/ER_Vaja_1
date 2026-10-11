package problems;

import java.util.ArrayList;

public class Rosenbrock extends Problem {

    public Rosenbrock() {
        setName("Rosenbrock");
        setLowerBound(-5.0);
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
