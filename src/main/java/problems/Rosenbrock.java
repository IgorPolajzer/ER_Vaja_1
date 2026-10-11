package problems;

import java.util.ArrayList;

public class Rosenbrock extends Problem {

    public Rosenbrock() {
        setName("Rosenbrock");
        setLowerBound(-5.0);
        setUpperBound(10.0);
    }

    @Override
    public double evaluate(ArrayList<Double> x_star) throws Exception {
        setDfromInput(x_star);

        var result = 0.0;
        for(var i = 0; i < getD() - 1; i++) {
            var x = x_star.get(i);
            var x_plus_one = x_star.get(i + 1);

            checkBounds(x);
            checkBounds(x_plus_one);

            result += 100 * Math.pow((x_plus_one - (x * x)), 2) + Math.pow((x - 1), 2);
        }

        return result;
    }

    @Override
    int generateRandomSolution() {
        return 0;
    }
}
