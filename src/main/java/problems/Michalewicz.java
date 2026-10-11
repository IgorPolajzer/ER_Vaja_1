package problems;

import java.util.ArrayList;

public class Michalewicz extends Problem {

    Michalewicz(String name, int d) {
        setD(d);
        setName(name);
        setLowerBound(0.0);
        setUpperBound(Math.PI);
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
