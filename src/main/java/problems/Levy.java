package problems;

import java.util.ArrayList;

public class Levy extends Problem {

    Levy(String name, int d) {
        setD(d);
        setName(name);
        setLowerBound(-10.0);
        setUpperBound(10.0);
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
