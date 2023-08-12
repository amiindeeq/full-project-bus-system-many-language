using System;
using System.Collections.Generic;

namespace CarRentalSystem
{
    class Car
    {
        public string CarId { get; set; }
        public string Make { get; set; }
        public string Model { get; set; }
        public decimal PricePerDay { get; set; }
        public bool Available { get; set; }
    }

    class RentalSystem
    {
        private List<Car> cars;
        private Dictionary<string, List<Car>> reservations;

        public RentalSystem()
        {
            cars = new List<Car>();
            reservations = new Dictionary<string, List<Car>>();
        }

        public void AddCar(Car car)
        {
            cars.Add(car);
        }

        public void RemoveCar(Car car)
        {
            cars.Remove(car);
        }

        public void MakeReservation(string customerId, Car car, int days)
        {
            if (!car.Available)
            {
                Console.WriteLine($"Car {car.CarId} is not available for the selected dates.");
                return;
            }

            if (!reservations.ContainsKey(customerId))
            {
                reservations[customerId] = new List<Car>();
            }

            reservations[customerId].Add(car);
            car.Available = false;
            Console.WriteLine($"Reservation made successfully for Car {car.CarId} for {days} days.");
        }

        public void ReturnCar(string customerId, Car car)
        {
            if (!reservations.ContainsKey(customerId))
            {
                Console.WriteLine($"No reservations found for customer {customerId}");
                return;
            }

            var customerReservations = reservations[customerId];
            if (customerReservations.Contains(car))
            {
                customerReservations.Remove(car);
                car.Available = true;
                Console.WriteLine($"Car {car.CarId} returned successfully.");
            }
            else
            {
                Console.WriteLine($"Car {car.CarId} is not reserved for customer {customerId}");
            }
        }

        public void GenerateInvoice(string customerId)
        {
            if (!reservations.ContainsKey(customerId))
            {
                Console.WriteLine($"No reservations found for customer {customerId}");
                return;
            }

            var customerReservations = reservations[customerId];
            decimal totalCost = 0.0m;

            Console.WriteLine($"\nInvoice for Customer {customerId}");
            Console.WriteLine("--------------------------------------------");
            foreach (var car in customerReservations)
            {
                decimal cost = car.PricePerDay;
                totalCost += cost;
                Console.WriteLine($"Car ID: {car.CarId}, Make: {car.Make}, Model: {car.Model}, Cost per day: ${cost}");
            }
            Console.WriteLine("--------------------------------------------");
            Console.WriteLine("Total Cost: $" + totalCost);
        }
    }

    class Program
    {
        static void Main(string[] args)
        {
            RentalSystem rentalSystem = new RentalSystem();

            Car car1 = new Car { CarId = "C001", Make = "Toyota", Model = "Camry", PricePerDay = 50.0m, Available = true };
            Car car2 = new Car { CarId = "C002", Make = "Honda", Model = "Accord", PricePerDay = 60.0m, Available = true };
            Car car3 = new Car { CarId = "C003", Make = "Ford", Model = "Mustang", PricePerDay = 100.0m, Available = true };

            rentalSystem.AddCar(car1);
            rentalSystem.AddCar(car2);
            rentalSystem.AddCar(car3);

            rentalSystem.MakeReservation("CUST001", car1, 5);
            rentalSystem.MakeReservation("CUST001", car2, 3);
            rentalSystem.MakeReservation("CUST002", car3, 7);

            rentalSystem.GenerateInvoice("CUST001");

            rentalSystem.ReturnCar("CUST001", car1);
            rentalSystem.ReturnCar("CUST002", car3);

            rentalSystem.GenerateInvoice("CUST001");
            rentalSystem.GenerateInvoice("CUST002");
        }
    }
}using System;
using System.Collections.Generic;

class Car
{
    public string CarId { get; set; }
    public string Make { get; set; }
    public string Model { get; set; }
    public decimal PricePerDay { get; set; }
    public bool Available { get; set; }
}

class RentalSystem
{
    private List<Car> cars;
    private Dictionary<string, List<Car>> reservations;

    public RentalSystem()
    {
        cars = new List<Car>();
        reservations = new Dictionary<string, List<Car>>();
    }

    public void AddCar(Car car)
    {
        cars.Add(car);
    }

    public void RemoveCar(Car car)
    {
        cars.Remove(car);
    }

    public void MakeReservation(string customerId, Car car, int days)
    {
        if (!car.Available)
        {
            Console.WriteLine($"Car {car.CarId} is not available for the selected dates.");
            return;
        }

        if (!reservations.ContainsKey(customerId))
        {
            reservations[customerId] = new List<Car>();
        }

        reservations[customerId].Add(car);
        car.Available = false;
        Console.WriteLine($"Reservation made successfully for Car {car.CarId} for {days} days.");
    }

    public void ReturnCar(string customerId, Car car)
    {
        if (!reservations.ContainsKey(customerId))
        {
            Console.WriteLine($"No reservations found for customer {customerId}");
            return;
        }

        var customerReservations = reservations[customerId];
        if (customerReservations.Contains(car))
        {
            customerReservations.Remove(car);
            car.Available = true;
            Console.WriteLine($"Car {car.CarId} returned successfully.");
        }
        else
        {
            Console.WriteLine($"Car {car.CarId} is not reserved for customer {customerId}");
        }
    }

    public void GenerateInvoice(string customerId)
    {
        if (!reservations.ContainsKey(customerId))
        {
            Console.WriteLine($"No reservations found for customer {customerId}");
            return;
        }

        var customerReservations = reservations[customerId];
        decimal totalCost = 0.0m;

        Console.WriteLine($"\nInvoice for Customer {customerId}");
        Console.WriteLine("--------------------------------------------");
        foreach (var car in customerReservations)
        {
            decimal cost = car.PricePerDay;
            totalCost += cost;
            Console.WriteLine($"Car ID: {car.CarId}, Make: {car.Make}, Model: {car.Model}, Cost per day: ${cost}");
        }
        Console.WriteLine("--------------------------------------------");
        Console.WriteLine("Total Cost: $" + totalCost);
    }
}

class Program
{
    static void Main(string[] args)
    {
        RentalSystem rentalSystem = new RentalSystem();

        Car car1 = new Car { CarId = "C001", Make = "Toyota", Model = "Camry", PricePerDay = 50.0m, Available = true };
        Car car2 = new Car { CarId = "C002", Make = "Honda", Model = "Accord", PricePerDay = 60.0m, Available = true };
        Car car3 = new Car { CarId = "C003", Make = "Ford", Model = "Mustang", PricePerDay = 100.0m, Available = true };

        rentalSystem.AddCar(car1);
        rentalSystem.AddCar(car2);
        rentalSystem.AddCar(car3);

        rentalSystem.MakeReservation("CUST001", car1, 5);
        rentalSystem.MakeReservation("CUST001", car2, 3);
        rentalSystem.MakeReservation("CUST002", car3, 7);

        rentalSystem.GenerateInvoice("CUST001");

        rentalSystem.ReturnCar("CUST001", car1);
        rentalSystem.ReturnCar("CUST002", car3);

        rentalSystem.GenerateInvoice("CUST001");
        rentalSystem.GenerateInvoice("CUST002");
    }
}