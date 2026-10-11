package problems;

import java.util.ArrayList;

public class Schwefel26 extends Problem {

    Schwefel26(String name, int d) {
        setD(d);
        setName(name);
        setLowerBound(-500.0);
        setUpperBound(500.0);
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
