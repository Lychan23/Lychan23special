from pynput.mouse import Controller, Listener

# Set the DPI and acceleration factor
dpi = 800
acceleration = 2

# Create a mouse controller
mouse = Controller()

# Define the on_move callback function
def on_move(x, y):
    # Calculate the new cursor speed based on DPI and acceleration factor
    cursor_speed = dpi * acceleration
    # Set the new cursor speed
    mouse.speed = cursor_speed

# Create a mouse listener
with Listener(on_move=on_move) as listener:
    # Start listening for mouse events
    listener.join()
