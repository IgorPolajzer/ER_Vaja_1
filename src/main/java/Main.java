import problems.Sphere;

void main() {
    var sphere = new Sphere("Sphere", 2);
    var specimen = new ArrayList<>(List.of(5.12, 5.12));
    var res = sphere.evaluate(specimen);
    System.out.println(res);
}
