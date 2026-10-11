package problems;

import java.util.ArrayList;

public class Ackley extends Problem {

    Ackley(String name, int d) {
        setD(d);
        setName(name);
        setLowerBound(-32.768);
        setUpperBound(32.768);
    }

    @Override
    public double evaluate(ArrayList<Double> x) {
        return 0;
    }

    @Override
    int generateRandomSolution() {
        return 0;
    }
}
