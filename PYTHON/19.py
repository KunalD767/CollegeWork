import tkinter as tk
from tkinter import messagebox

def perform_calculation():
    try:
        num1 = float(entry1.get())
        num2 = float(entry2.get())
        operation = operation_var.get()

        if operation == "Add":
            result = num1 + num2
        elif operation == "Subtract":
            result = num1 - num2
        elif operation == "Multiply":
            result = num1 * num2
        elif operation == "Divide":
            if num2 == 0:
                raise ZeroDivisionError("Cannot divide by zero.")
            result = num1 / num2
        else:
            messagebox.showerror("Error", "Please select a valid operation.")
            return

        result_label.config(text=f"Result: {result}")
        result_text.delete("1.0", tk.END)
        result_text.insert(tk.END, f"{result}")

    except ValueError:
        messagebox.showerror("Error", "Please enter valid numeric values.")
    except ZeroDivisionError as e:
        messagebox.showerror("Error", str(e))
    except Exception as e:
        messagebox.showerror("Error", f"An unexpected error occurred: {e}")

def clear_fields():
    entry1.delete(0, tk.END)
    entry2.delete(0, tk.END)
    result_label.config(text="Result: ")
    result_text.delete("1.0", tk.END)

# Create the main window
root = tk.Tk()
root.title("Simple Calculator")
root.geometry("300x400")

# Create and place widgets
label1 = tk.Label(root, text="Enter first number:")
label1.pack(pady=5)
entry1 = tk.Entry(root)
entry1.pack(pady=5)

label2 = tk.Label(root, text="Enter second number:")
label2.pack(pady=5)
entry2 = tk.Entry(root)
entry2.pack(pady=5)

operation_var = tk.StringVar()
operation_var.set("Add")

operation_label = tk.Label(root, text="Select Operation:")
operation_label.pack(pady=5)

operation_menu = tk.OptionMenu(root, operation_var, "Add", "Subtract", "Multiply", "Divide")
operation_menu.pack(pady=5)

calculate_button = tk.Button(root, text="Calculate", command=perform_calculation)
calculate_button.pack(pady=5)

clear_button = tk.Button(root, text="Clear", command=clear_fields)
clear_button.pack(pady=5)

result_label = tk.Label(root, text="Result: ")
result_label.pack(pady=10)

result_text = tk.Text(root, height=5, width=30)
result_text.pack(pady=5)

# Run the main loop
root.mainloop()
