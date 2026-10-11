package problems;

import java.util.ArrayList;

public class Rastrigin extends Problem {

    public Rastrigin() {
        setName("Rastrigin");
        setLowerBound(-5.12);
        setUpperBound(5.12);
    }

    @Override
    public double evaluate(ArrayList<Double> x_star) throws Exception {
        setDfromInput(x_star);

        var sum = 0.0;

        for(var i = 0; i < getD(); i++) {
            var x = x_star.get(i);

            checkBounds(x);

            sum += x * x - 10 * Math.cos(2 * Math.PI * x);
        }

        return 10 * getD() + sum;
    }

    @Override
    int generateRandomSolution() {
        return 0;
    }
}
