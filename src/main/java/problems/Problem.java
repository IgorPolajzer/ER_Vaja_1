package problems;

import lombok.Getter;
import lombok.Setter;

import java.util.ArrayList;

@Getter
@Setter
public abstract class Problem {

    String name;
    int d;
    Double lowerBound;
    Double upperBound;

    public abstract double evaluate(ArrayList<Double> x);

    abstract int generateRandomSolution();
}
