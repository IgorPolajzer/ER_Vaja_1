package problems;

import java.util.ArrayList;

public class Rastrigin extends Problem {

    Rastrigin(String name, int d) {
        setD(d);
        setName(name);
        setLowerBound(-5.12);
        setUpperBound(5.12);
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
