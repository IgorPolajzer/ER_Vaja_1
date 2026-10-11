package problem;

import lombok.SneakyThrows;
import org.junit.jupiter.params.ParameterizedTest;
import org.junit.jupiter.params.provider.ValueSource;
import problems.*;

import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.stream.Collectors;
import java.util.stream.IntStream;

import static org.junit.jupiter.api.Assertions.assertEquals;

public class ProblemTest {

    @ParameterizedTest
    @ValueSource(ints = {2, 5, 10})
    @SneakyThrows
    void testSphere(int d) {
        var problem = new Sphere();
        var specimen = new ArrayList<>(Collections.nCopies(d, 0.0));
        var fitness = problem.evaluate(specimen);

        assertEquals(0.0, fitness);
    }

    @ParameterizedTest
    @ValueSource(ints = {2, 5, 10})
    @SneakyThrows
    void testAckely(int d) {
        var problem = new Ackley();
        var specimen = new ArrayList<>(Collections.nCopies(d, 0.0));
        var fitness = problem.evaluate(specimen);

        assertEquals(0.0, fitness, 1e-9);
    }

    @ParameterizedTest
    @ValueSource(ints = {2, 5, 10})
    @SneakyThrows
    void testGriewank(int d) {
        var problem = new Griewank();
        var specimen = new ArrayList<>(Collections.nCopies(d, 0.0));
        var fitness = problem.evaluate(specimen);

        assertEquals(0.0, fitness);
    }

    @ParameterizedTest
    @ValueSource(ints = {2, 5, 10})
    @SneakyThrows
    void testRastrigin(int d) {
        var problem = new Rastrigin();
        var specimen = new ArrayList<>(Collections.nCopies(d, 0.0));
        var fitness = problem.evaluate(specimen);

        assertEquals(0.0, fitness);
    }

    @ParameterizedTest
    @ValueSource(ints = {2, 5, 10})
    @SneakyThrows
    void testSchwefel26(int d) {
        var problem = new Schwefel26();
        var specimen = new ArrayList<>(Collections.nCopies(d, 420.968746));
        var fitness = problem.evaluate(specimen);

        assertEquals(-418.982887272433799807913601398 * d, fitness, 1e-9);
    }

    @ParameterizedTest
    @ValueSource(ints = {2, 5, 10})
    @SneakyThrows
    void testRosenbrock(int d) {
        var problem = new Rosenbrock();
        var specimen = new ArrayList<>(Collections.nCopies(d, 1.0));
        var fitness = problem.evaluate(specimen);

        assertEquals(0, fitness);
    }

    @ParameterizedTest
    @ValueSource(ints = {2, 5, 10})
    @SneakyThrows
    void testTrid(int d) {
        var problem = new Trid();
        var dimCtr = IntStream.rangeClosed(1, d).toArray();
        var specimen = new ArrayList<Double>();

        for (var i : dimCtr) {
            specimen.add(i * (d + 1.0 - i));
        }

        var fitness = problem.evaluate(specimen);

        var expected = - d * (d + 4.0) * (d - 1.0) / 6.0;
        assertEquals(expected, fitness);
    }

    @ParameterizedTest
    @ValueSource(ints = {2, 5, 10})
    @SneakyThrows
    void testLevy(int d) {
        var problem = new Levy();
        var specimen = new ArrayList<>(Collections.nCopies(d, 1.0));
        var fitness = problem.evaluate(specimen);

        assertEquals(0, fitness, 1e-9);
    }
}
