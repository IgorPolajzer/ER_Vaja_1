package problems;

import java.util.ArrayList;

public class Trid extends Problem {

    Trid(String name, int d) {
        setD(d);
        setName(name);
        setLowerBound((double) -(d * d));
        setUpperBound((double) (d * d));
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
