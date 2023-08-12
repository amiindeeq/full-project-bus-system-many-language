class Car {
    constructor(carId, make, model, pricePerDay) {
      this.carId = carId;
      this.make = make;
      this.model = model;
      this.pricePerDay = pricePerDay;
      this.available = true;
    }
  
    getCarId() {
      return this.carId;
    }
  
    getMake() {
      return this.make;
    }
  
    getModel() {
      return this.model;
    }
  
    getPricePerDay() {
      return this.pricePerDay;
    }
  
    isAvailable() {
      return this.available;
    }
  
    setAvailable(available) {
      this.available = available;
    }
  }
  
  class RentalSystem {
    constructor() {
      this.cars = [];
      this.reservations = {};
    }
  
    addCar(car) {
      this.cars.push(car);
    }
  
    removeCar(car) {
      const index = this.cars.indexOf(car);
      if (index !== -1) {
        this.cars.splice(index, 1);
      }
    }
  
    makeReservation(customerId, car, days) {
      if (!car.isAvailable()) {
        console.log(`Car ${car.getCarId()} is not available for the selected dates.`);
        return;
      }
  
      if (!this.reservations[customerId]) {
        this.reservations[customerId] = [];
      }
  
      this.reservations[customerId].push(car);
      car.setAvailable(false);
      console.log(`Reservation made successfully for Car ${car.getCarId()} for ${days} days.`);
    }
  
    returnCar(customerId, car) {
      if (!this.reservations[customerId]) {
        console.log(`No reservations found for customer ${customerId}`);
        return;
      }
  
      const customerReservations = this.reservations[customerId];
      const index = customerReservations.indexOf(car);
      if (index !== -1) {
        customerReservations.splice(index, 1);
        car.setAvailable(true);
        console.log(`Car ${car.getCarId()} returned successfully.`);
      } else {
        console.log(`Car ${car.getCarId()} is not reserved for customer ${customerId}`);
      }
    }
  
    generateInvoice(customerId) {
      if (!this.reservations[customerId]) {
        console.log(`No reservations found for customer ${customerId}`);
        return;
      }
  
      const customerReservations = this.reservations[customerId];
      let totalCost = 0.0;
  
      console.log(`\nInvoice for Customer ${customerId}`);
      console.log("--------------------------------------------");
      customerReservations.forEach((car) => {
        const cost = car.getPricePerDay();
        totalCost += cost;
        console.log(`Car ID: ${car.getCarId()}, Make: ${car.getMake()}, Model: ${car.getModel()}, Cost per day: $${cost}`);
      });
      console.log("--------------------------------------------");
      console.log("Total Cost: $", totalCost);
    }
  }
  
  const rentalSystem = new RentalSystem();
  
  const car1 = new Car("C001", "Toyota", "Camry", 50.0);
  const car2 = new Car("C002", "Honda", "Accord", 60.0);
  const car3 = new Car("C003", "Ford", "Mustang", 100.0);
  
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