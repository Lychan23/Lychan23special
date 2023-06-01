from pynput.mouse import Controller, Listener
import math
import tkinter as tk

# Define the angle snapping threshold in degrees
angle_threshold = 15

# Create a mouse controller
mouse = Controller()

# Create a GUI window
window = tk.Tk()
window.title("Angle Snapper")
window.geometry("400x300")

# Create a canvas to display the cursor position
canvas = tk.Canvas(window, width=400, height=300)
canvas.pack()

# Define the on_move callback function
def on_move(x, y):
    # Calculate the angle between the current cursor position and the origin
    angle = math.degrees(math.atan2(y, x))

    # Snap the angle to the nearest multiple of angle_threshold
    snapped_angle = round(angle / angle_threshold) * angle_threshold

    # Convert the snapped angle back to radians
    snapped_angle_rad = math.radians(snapped_angle)

    # Calculate the new cursor position based on the snapped angle
    radius = math.sqrt(x**2 + y**2)
    new_x = round(radius * math.cos(snapped_angle_rad))
    new_y = round(radius * math.sin(snapped_angle_rad))

    # Move the cursor to the new position
    mouse.position = (new_x, new_y)

    # Update the canvas with the current cursor position
    canvas.delete("all")
    canvas.create_text(200, 150, text=f"Cursor Position: {new_x}, {new_y}", font=("Arial", 16), fill="black")

# Create a mouse listener
with Listener(on_move=on_move) as listener:
    # Start listening for mouse events
    listener.start()

    # Start the GUI event loop
    window.mainloop()
