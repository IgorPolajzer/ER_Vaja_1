package problems;

import java.util.ArrayList;

public class Griewank extends Problem {

    public Griewank() {
        setName("Griewank");
        setLowerBound(-600.0);
        setUpperBound(600.0);
    }

    @Override
    public double evaluate(ArrayList<Double> x_star) throws Exception {
        setDfromInput(x_star);

        var firstTerm = 0.0;
        var secondTerm = 0.0;
        for(var i = 0; i < getD(); i++) {
            var x = x_star.get(i);

            checkBounds(x);

            firstTerm += ((x * x) / 4000);
            secondTerm *= Math.cos(x / Math.sqrt(i + 1)) + 1;
        }

        return firstTerm - secondTerm;
    }

    @Override
    int generateRandomSolution() {
        return 0;
    }
}
