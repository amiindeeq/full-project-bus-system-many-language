import java.util.*;

class Car {
    private String carId;
    private String make;
    private String model;
    private double pricePerDay;
    private boolean available;

    public Car(String carId, String make, String model, double pricePerDay) {
        this.carId = carId;
        this.make = make;
        this.model = model;
        this.pricePerDay = pricePerDay;
        this.available = true;
    }

    public String getCarId() {
        return carId;
    }

    public String getMake() {
        return make;
    }

    public String getModel() {
        return model;
    }

    public double getPricePerDay() {
        return pricePerDay;
    }

    public boolean isAvailable() {
        return available;
    }

    public void setAvailable(boolean available) {
        this.available = available;
    }
}

class RentalSystem {
    private List<Car> cars;
    private Map<String, List<Car>> reservations;

    public RentalSystem() {
        cars = new ArrayList<>();
        reservations = new HashMap<>();
    }

    public void addCar(Car car) {
        cars.add(car);
    }

    public void removeCar(Car car) {
        cars.remove(car);
    }

    public void makeReservation(String customerId, Car car, int days) {
        if (!car.isAvailable()) {
            System.out.println("Car " + car.getCarId() + " is not available for the selected dates.");
            return;
        }

        if (!reservations.containsKey(customerId))
            reservations.put(customerId, new ArrayList<>());

        reservations.get(customerId).add(car);
        car.setAvailable(false);
        System.out.println("Reservation made successfully for Car " + car.getCarId() + " for " + days + " days.");
    }

    public void returnCar(String customerId, Car car) {
        if (!reservations.containsKey(customerId)) {
            System.out.println("No reservations found for customer " + customerId);
            return;
        }

        List<Car> customerReservations = reservations.get(customerId);
        if (!customerReservations.contains(car)) {
            System.out.println("Car " + car.getCarId() + " is not reserved for customer " + customerId);
            return;
        }

        customerReservations.remove(car);
        car.setAvailable(true);
        System.out.println("Car " + car.getCarId() + " returned successfully.");
    }

    public void generateInvoice(String customerId) {
        if (!reservations.containsKey(customerId)) {
            System.out.println("No reservations found for customer " + customerId);
            return;
        }

        List<Car> customerReservations = reservations.get(customerId);
        double totalCost = 0.0;

        System.out.println("\nInvoice for Customer " + customerId);
        System.out.println("--------------------------------------------");
        for (Car car : customerReservations) {
            double cost = car.getPricePerDay();
            totalCost += cost;
            System.out.println("Car ID: " + car.getCarId() + ", Make: " + car.getMake() + ", Model: " + car.getModel() + ", Cost per day: $" + cost);
        }
        System.out.println("--------------------------------------------");
        System.out.println("Total Cost: $" + totalCost);
    }
}

public class CarRentalSystem {
    public static void main(String[] args) {
        RentalSystem rentalSystem = new RentalSystem();

        Car car1 = new Car("C001", "Toyota", "Camry", 50.0);
        Car car2 = new Car("C002", "Honda", "Accord", 60.0);
        Car car3 = new Car("C003", "Ford", "Mustang", 100.0);

        rentalSystem.addCar(car1);
        rentalSystem.addCar(car2);
        rentalSystem.addCar(car3);

        rentalSystem.makeReservation("CUST001", car1, 5);
        rentalSystem.makeReservation("CUST001", car2, 3);
        rentalSystem.makeReservation("CUST002", car3, 7);

        rentalSystem.generateInvoice("CUST001");

        rentalSystem.returnCar("CUST001", car1);
        rentalSystem.returnCar("CUST002", car3);

        rentalSystem.generateInvoice("CUST001");
        rentalSystem.generateInvoice("CUST002");
    }
}