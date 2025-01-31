from flask import Flask, render_template, request, redirect, url_for, flash
import sqlite3
from datetime import datetime

app = Flask(__name__)
app.secret_key = 'your_secret_key'

# Database initialization
def init_db():
    conn = sqlite3.connect('hotel_inventory.db')
    c = conn.cursor()
    c.execute('''CREATE TABLE IF NOT EXISTS products (
                    id INTEGER PRIMARY KEY AUTOINCREMENT,
                    name TEXT NOT NULL,
                    category TEXT NOT NULL,
                    quantity INTEGER NOT NULL,
                    unit_price REAL NOT NULL,
                    supplier TEXT NOT NULL,
                    reorder_level INTEGER NOT NULL,
                    last_updated TEXT NOT NULL
                )''')
    c.execute('''CREATE TABLE IF NOT EXISTS transactions (
                    id INTEGER PRIMARY KEY AUTOINCREMENT,
                    product_id INTEGER NOT NULL,
                    transaction_type TEXT NOT NULL,
                    quantity INTEGER NOT NULL,
                    transaction_date TEXT NOT NULL,
                    FOREIGN KEY (product_id) REFERENCES products (id)
                )''')
    conn.commit()
    conn.close()

# Home page - Display all products
@app.route('/')
def index():
    conn = sqlite3.connect('hotel_inventory.db')
    c = conn.cursor()
    c.execute('SELECT * FROM products')
    products = c.fetchall()
    conn.close()

    # Check for low stock alerts
    low_stock_products = [product for product in products if product[3] <= product[6]]
    if low_stock_products:
        flash(f'Alert: {len(low_stock_products)} product(s) are below reorder level!', 'warning')

    return render_template('index.html', products=products)

# Add a new product
@app.route('/add', methods=['GET', 'POST'])
def add_product():
    if request.method == 'POST':
        name = request.form['name']
        category = request.form['category']
        quantity = int(request.form['quantity'])
        unit_price = float(request.form['unit_price'])
        supplier = request.form['supplier']
        reorder_level = int(request.form['reorder_level'])
        last_updated = datetime.now().strftime('%Y-%m-%d %H:%M:%S')

        conn = sqlite3.connect('hotel_inventory.db')
        c = conn.cursor()
        c.execute('''INSERT INTO products 
                    (name, category, quantity, unit_price, supplier, reorder_level, last_updated) 
                    VALUES (?, ?, ?, ?, ?, ?, ?)''',
                  (name, category, quantity, unit_price, supplier, reorder_level, last_updated))
        conn.commit()
        conn.close()

        flash('Product added successfully!', 'success')
        return redirect(url_for('index'))

    return render_template('add_product.html')

# Update a product
@app.route('/update/<int:id>', methods=['GET', 'POST'])
def update_product(id):
    conn = sqlite3.connect('hotel_inventory.db')
    c = conn.cursor()
    c.execute('SELECT * FROM products WHERE id = ?', (id,))
    product = c.fetchone()

    if request.method == 'POST':
        name = request.form['name']
        category = request.form['category']
        quantity = int(request.form['quantity'])
        unit_price = float(request.form['unit_price'])
        supplier = request.form['supplier']
        reorder_level = int(request.form['reorder_level'])
        last_updated = datetime.now().strftime('%Y-%m-%d %H:%M:%S')

        c.execute('''UPDATE products 
                    SET name = ?, category = ?, quantity = ?, unit_price = ?, supplier = ?, reorder_level = ?, last_updated = ? 
                    WHERE id = ?''',
                  (name, category, quantity, unit_price, supplier, reorder_level, last_updated, id))
        conn.commit()
        conn.close()

        flash('Product updated successfully!', 'success')
        return redirect(url_for('index'))

    conn.close()
    return render_template('update_product.html', product=product)

# Delete a product
@app.route('/delete/<int:id>')
def delete_product(id):
    conn = sqlite3.connect('hotel_inventory.db')
    c = conn.cursor()
    c.execute('DELETE FROM products WHERE id = ?', (id,))
    conn.commit()
    conn.close()

    flash('Product deleted successfully!', 'success')
    return redirect(url_for('index'))

# View financial reports
@app.route('/reports')
def financial_reports():
    conn = sqlite3.connect('hotel_inventory.db')
    c = conn.cursor()
    c.execute('''SELECT p.name, p.category, p.quantity, p.unit_price, 
                SUM(t.quantity) as total_sold, 
                (p.quantity * p.unit_price) as stock_value 
                FROM products p 
                LEFT JOIN transactions t ON p.id = t.product_id 
                GROUP BY p.id''')
    report_data = c.fetchall()
    conn.close()

    return render_template('reports.html', report_data=report_data)

if __name__ == '__main__':
    init_db()
    app.run(debug=True)