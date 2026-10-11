package problems;

import java.util.ArrayList;

public class Sphere extends Problem {

    public Sphere() {
        setName("Sphere");
        setLowerBound(-100.0);
        setUpperBound(100.0);
    }

    @Override
    public double evaluate(ArrayList<Double> x_star) throws Exception {
        setDfromInput(x_star);

        var result = 0.0;

        for(int i = 0; i < getD(); i++) {
            var x = x_star.get(i);

            checkBounds(x);

            result += x * x;
        }

        return result;
    }

    @Override
    int generateRandomSolution() {
        return 0;
    }
}
