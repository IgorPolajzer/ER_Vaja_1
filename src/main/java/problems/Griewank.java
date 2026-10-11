package problems;

import java.util.ArrayList;

public class Griewank extends Problem {

    public Griewank() {
        setName("Griewank");
        setLowerBound(-600.0);
        setUpperBound(600.0);
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
