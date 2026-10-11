package problems;

import java.util.ArrayList;

public class Sphere extends Problem {

    public Sphere(String name, int d) {
        setD(d);
        setName(name);
        setLowerBound(-100.0);
        setUpperBound(100.0);
    }

    @Override
    public double evaluate(ArrayList<Double> x) {
        var result = 0.0;

        for(int i = 0; i < getD(); i++) {
            result += x.get(i) * x.get(i);
        }

        return result;
    }

    @Override
    int generateRandomSolution() {
        return 0;
    }
}
