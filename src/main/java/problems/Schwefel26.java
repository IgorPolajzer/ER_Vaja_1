package problems;

import java.util.ArrayList;

public class Schwefel26 extends Problem {

    public Schwefel26() {
        setName("Schwefel26");
        setLowerBound(-500.0);
        setUpperBound(500.0);
    }

    @Override
    public double evaluate(ArrayList<Double> x_star) throws Exception {
        setDfromInput(x_star);

        var sum = 0.0;
        for(var i = 0; i < getD(); i++) {
            var x = x_star.get(i);

            checkBounds(x);

            sum += x * Math.sin(Math.sqrt(Math.abs(x)));
        }

        return -sum;
    }

    @Override
    int generateRandomSolution() {
        return 0;
    }
}
