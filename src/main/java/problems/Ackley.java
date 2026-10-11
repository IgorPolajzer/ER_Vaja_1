package problems;

import java.util.ArrayList;

public class Ackley extends Problem {

    public Ackley() {
        setName("Ackley");
        setLowerBound(-32.768);
        setUpperBound(32.768);
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
