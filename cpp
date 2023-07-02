#include <iostream>
#include <vector>
#include <string>

class Article {
private:
    int articleID;
    std::string name;
    std::string description;
    double price;
    int quantity;

public:
    Article(int id, const std::string& n, const std::string& desc, double p, int q)
        : articleID(id), name(n), description(desc), price(p), quantity(q) {}

    int getArticleID() const {
        return articleID;
    }

    std::string getName() const {
        return name;
    }

    std::string getDescription() const {
        return description;
    }

    double getPrice() const {
        return price;
    }

    int getQuantity() const {
        return quantity;
    }
};

class Customer {
private:
    int customerID;
    std::string name;
    std::string email;
    std::string phone;
    std::string address;

public:
    Customer(int id, const std::string& n, const std::string& e, const std::string& p, const std::string& a)
        : customerID(id), name(n), email(e), phone(p), address(a) {}

    int getCustomerID() const {
        return customerID;
    }

    std::string getName() const {
        return name;
    }

    std::string getEmail() const {
        return email;
    }

    std::string getPhone() const {
        return phone;
    }

    std::string getAddress() const {
        return address;
    }
};

class SalesInvoice {
private:
    int invoiceID;
    Customer customer;
    std::vector<Article> articles;
    std::string invoiceDate;
    double totalAmount;

public:
    SalesInvoice(int id, const Customer& c, const std::string& date)
        : invoiceID(id), customer(c), invoiceDate(date), totalAmount(0) {}

    int getInvoiceID() const {
        return invoiceID;
    }

    Customer getCustomer() const {
        return customer;
    }

    std::string getInvoiceDate() const {
        return invoiceDate;
    }

    double getTotalAmount() const {
        return totalAmount;
    }

    void addArticle(const Article& article) {
        articles.push_back(article);
        totalAmount += article.getPrice();
    }

    void displayInvoice() {
        std::cout << "Invoice ID: " << invoiceID << std::endl;
        std::cout << "Customer: " << customer.getName() << std::endl;
        std::cout << "Invoice Date: " << invoiceDate << std::endl;
        std::cout << "Total Amount: " << totalAmount << std::endl;
        std::cout << "Articles:" << std::endl;

        for (const auto& article : articles) {
            std::cout << "- " << article.getName() << " (" << article.getQuantity() << " units)" << std::endl;
        }
    }
};

int main() {
    // Create sample objects
    Customer customer(1, "John Doe", "john.doe@example.com", "1234567890", "123 Main St");
    Article article1(1, "Product 1", "Description 1", 10.99, 5);
    Article article2(2, "Product 2", "Description 2", 19.99, 3);

    // Create a sales invoice
    SalesInvoice invoice(1, customer, "2023-07-02");

    // Add articles to the sales invoice
    invoice.addArticle(article1);
    invoice.addArticle(article2);
