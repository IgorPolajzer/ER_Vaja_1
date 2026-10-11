package problems;

import java.util.ArrayList;

public class Griewank extends Problem {

    Griewank(String name, int d) {
        setD(d);
        setName(name);
        setLowerBound(-600.0);
        setUpperBound(600.0);
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
