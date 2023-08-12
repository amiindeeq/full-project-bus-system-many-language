class Car:
    def __init__(self, car_id, make, model, price_per_day):
        self.car_id = car_id
        self.make = make
        self.model = model
        self.price_per_day = price_per_day
        self.available = True

    def get_car_id(self):
        return self.car_id

    def get_make(self):
        return self.make

    def get_model(self):
        return self.model

    def get_price_per_day(self):
        return self.price_per_day

    def is_available(self):
        return self.available

    def set_available(self, available):
        self.available = available


class RentalSystem:
    def __init__(self):
        self.cars = []
        self.reservations = {}

    def add_car(self, car):
        self.cars.append(car)

    def remove_car(self, car):
        self.cars.remove(car)

    def make_reservation(self, customer_id, car, days):
        if not car.is_available():
            print(f"Car {car.get_car_id()} is not available for the selected dates.")
            return

        if customer_id not in self.reservations:
            self.reservations[customer_id] = []

        self.reservations[customer_id].append(car)
        car.set_available(False)
        print(f"Reservation made successfully for Car {car.get_car_id()} for {days} days.")

    def return_car(self, customer_id, car):
        if customer_id not in self.reservations:
            print(f"No reservations found for customer {customer_id}")
            return

        customer_reservations = self.reservations[customer_id]
        if car not in customer_reservations:
            print(f"Car {car.get_car_id()} is not reserved for customer {customer_id}")
            return

        customer_reservations.remove(car)
        car.set_available(True)
        print(f"Car {car.get_car_id()} returned successfully.")

    def generate_invoice(self, customer_id):
        if customer_id not in self.reservations:
            print(f"No reservations found for customer {customer_id}")
            return

        customer_reservations = self.reservations[customer_id]
        total_cost = 0.0

        print("\nInvoice for Customer", customer_id)
        print("--------------------------------------------")
        for car in customer_reservations:
            cost = car.get_price_per_day()
            total_cost += cost
            print(
                f"Car ID: {car.get_car_id()}, Make: {car.get_make()}, Model: {car.get_model()}, Cost per day: ${cost}"
            )
        print("--------------------------------------------")
        print("Total Cost: $", total_cost)


def main():
    rental_system = RentalSystem()

    car1 = Car("C001", "Toyota", "Camry", 50.0)
    car2 = Car("C002", "Honda", "Accord", 60.0)
    car3 = Car("C003", "Ford", "Mustang", 100.0)

    rental_system.add_car(car1)
    rental_system.add_car(car2)
    rental_system.add_car(car3)

    rental_system.make_reservation("CUST001", car1, 5)
    rental_system.make_reservation("CUST001", car2, 3)
    rental_system.make_reservation("CUST002", car3, 7)

    rental_system.generate_invoice("CUST001")

    rental_system.return_car("CUST001", car1)
    rental_system.return_car("CUST002", car3)

    rental_system.generate_invoice("CUST001")
    rental_system.generate_invoice("CUST002")


if __name__ == "__main__":
    main()