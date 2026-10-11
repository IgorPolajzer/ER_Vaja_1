package problems;

import java.util.ArrayList;

public class Michalewicz extends Problem {

    public Michalewicz() {
        setName("Michalewicz");
        setLowerBound(0.0);
        setUpperBound(Math.PI);
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
