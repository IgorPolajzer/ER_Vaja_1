package problems;

import java.util.ArrayList;

public class Trid extends Problem {

    public Trid() {
        setName("Trid");
    }

    @Override
    public void setD(int d) {
        super.setD(d);
        setLowerBound((double) -(d * d));
        setUpperBound((double) (d * d));
    }

    @Override
    public double evaluate(ArrayList<Double> x_star) throws Exception {
        setDfromInput(x_star);

        var firstTerm = 0.0;
        var secondTerm = 0.0;

        for(var i = 0; i < getD(); i++) {
            var x = x_star.get(i);
            checkBounds(x);

            firstTerm += Math.pow((x - 1), 2);

            if (i >= 1) {
                var x_minus_one = x_star.get(i - 1);
                checkBounds(x_minus_one);

                secondTerm += x * x_minus_one;
            }
        }

        return firstTerm - secondTerm;
    }

    @Override
    int generateRandomSolution() {
        return 0;
    }
}
