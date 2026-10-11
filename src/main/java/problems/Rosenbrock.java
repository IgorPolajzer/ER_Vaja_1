package problems;

import java.util.ArrayList;

public class Rosenbrock extends Problem {

    Rosenbrock(String name, int d) {
        setD(d);
        setName(name);
        setLowerBound(-5.0);
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
