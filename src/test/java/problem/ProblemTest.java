package problem;

import lombok.SneakyThrows;
import org.junit.jupiter.params.ParameterizedTest;
import org.junit.jupiter.params.provider.ValueSource;
import problems.Ackley;
import problems.Sphere;

import java.util.ArrayList;
import java.util.Collections;

import static org.junit.jupiter.api.Assertions.assertEquals;

public class ProblemTest {

    @ParameterizedTest
    @ValueSource(ints = {2, 5, 10})
    @SneakyThrows
    void testSphere(int d) {
        var sphere = new Sphere();
        var specimen = new ArrayList<>(Collections.nCopies(d, 0.0));
        var fitness = sphere.evaluate(specimen);

        assertEquals(0.0, fitness);
    }

    @ParameterizedTest
    @ValueSource(ints = {2, 5, 10})
    @SneakyThrows
    void testAckely(int d) {
        var ackley = new Ackley();
        var specimen = new ArrayList<>(Collections.nCopies(d, 0.0));
        var fitness = ackley.evaluate(specimen);

        assertEquals(0.0, fitness, 1e-9);
    }
}
