#include <gtk/gtk.h>
#include <stdbool.h>

#define MODE_TOGGLE                                     '0'
#define MODE_ON_OFF_ONLY                                '1'
#define MODE_ON_OFF_DURATION                            '2'
#define MODE_ON_OFF_INSTANT                             '3'

#define DURATION_MIN                                     1

#define HOURS_MIN                                        0
#define HOURS_MAX                                        23
#define MINUTES_MIN                                      0
#define MINUTES_MAX                                      59
#define SECONDS_MIN                                      0
#define SECONDS_MAX                                      59

GtkWidget *durationLabel, *durationEntry, *durationButton, *grid;
GtkWidget *hoursLabel, *hoursEntry, *minutesLabel, *minutesEntry, *secondsLabel, *secondsEntry,*instantButton;

GtkWidget *window;
GtkWidget *grid;
GtkWidget *button1;
GtkWidget *button2;
GtkWidget *button3;
GtkWidget *button4;
GtkWidget *quit;

char load = '0';
char mode = '0';
char on_off = '0';
int duration = 0;
int hours = 0;
int minutes = 0;
int seconds = 0;

/*
* Callback function of load window
*/
static void load_button_handler(GtkWidget *widget,gpointer data)
{

  if(widget == button1)
    load = '1';

  else if(widget == button2)
    load = '2';

  gtk_widget_destroy(window);
}

/*
* Call back function of mode window
*/
static void mode_button_handler(GtkWidget *widget,gpointer data)
{
  if(widget == button1)
    mode = '0';

  else if(widget == button2)
    mode = '1';

  else if(widget == button3)
    mode = '2';

  else if(widget == button4)
    mode = '3';

  gtk_widget_destroy(window);
}

/*
* Call back function of on_off window
*/
static void on_off_button_handler(GtkWidget *widget,gpointer data)
{

  if(widget == button1)
    on_off = '0';

  else if(widget == button2)
    on_off = '1';

  gtk_widget_destroy(window);
}

/*
* Brief - Callback function of duration window
*/
void duration_button_handler(GtkWidget *wid,gpointer data)
 {
  duration = atoi(gtk_entry_get_text(GTK_ENTRY(durationEntry)));

  if(duration < DURATION_MIN)
  {
    printf("Duration should be greate than 0. Please try again!\n");
  }

  else
  {
    gtk_widget_destroy(window);
  }
 }

/*
* Brief - Callback function of time instant window
*/
 void time_instant_button_handler(GtkWidget *wid,gpointer data)
{

  hours = atoi(gtk_entry_get_text(GTK_ENTRY(hoursEntry)));
  minutes = atoi(gtk_entry_get_text(GTK_ENTRY(minutesEntry)));
  seconds = atoi(gtk_entry_get_text(GTK_ENTRY(secondsEntry)));

  if((hours < HOURS_MIN) || (hours > HOURS_MAX))
  {
    printf("Hours value should be in the range 0-23 inclusive.\n");
  }

  else if((minutes < MINUTES_MIN) || (minutes > MINUTES_MAX))
  {
    printf("Minutes value should be in the range 0-59 inclusive.\n");
  }

  else if((seconds < SECONDS_MIN) || (seconds > SECONDS_MAX))
  {
    printf("Seconds value should be in the range 0-59 inclusive.\n");
  }

  else
  {
    gtk_widget_destroy(window);
  }

}

/*
* Brief - Used to get the first parameter in the packet that needs to be transmitted, i.e Load number
*/
static void load_window(GtkApplication *app, gpointer user_data)
{
  /* create a new window, and set its title */
  window = gtk_application_window_new (app);
  gtk_window_set_title (GTK_WINDOW (window), "Load Number");
  gtk_window_set_default_size(GTK_WINDOW(window), 400, 400);

  gtk_window_set_position(GTK_WINDOW(window), GTK_WIN_POS_CENTER);

  gtk_window_set_resizable(GTK_WINDOW(window), FALSE);

  /* Here we construct the container that is going pack our buttons */
  grid = gtk_grid_new ();

  /* Pack the container in the window */
  gtk_container_add (GTK_CONTAINER (window), grid);

  //Load 1 button
  button1 = gtk_button_new_with_label ("Load 1");
  g_signal_connect (button1, "clicked", G_CALLBACK (load_button_handler), NULL);

  gtk_grid_attach (GTK_GRID (grid), button1, 0, 0, 10, 10);

  //Load 2 button
  button2 = gtk_button_new_with_label ("Load 2");
  g_signal_connect (button2, "clicked", G_CALLBACK (load_button_handler), NULL);
  gtk_grid_attach (GTK_GRID (grid), button2, 0, 10, 10, 10);

  //Display the window
  gtk_widget_show_all(window);

}

/*
* Brief - Used to get the second parameter in the packet that needs to be transmitted, i.e mode of control
* The following are the modes in which the load can be controlled
* 0 - Togle the current state of the load
* 1 - Set / Reset the electrical load
* 2 - Set / Reset the electrical load for a specific duration of time
* 3 - Set / Reset the electrical load at a particular instant of time
*
* NOTE: Here Set / Reset refers to Turning the load On / Off
*/
static void mode_window(GtkApplication *app, gpointer user_data)
{

  /* create a new window, and set its title */
  window = gtk_application_window_new (app);
  gtk_window_set_title (GTK_WINDOW (window), "Mode");
  gtk_window_set_default_size(GTK_WINDOW(window), 400, 400);

  gtk_window_set_position(GTK_WINDOW(window), GTK_WIN_POS_CENTER);

  gtk_window_set_resizable(GTK_WINDOW(window), FALSE);

  /* Here we construct the container that is going pack our buttons */
  grid = gtk_grid_new ();

  /* Pack the container in the window */
  gtk_container_add (GTK_CONTAINER (window), grid);

  //Load 1st button
  button1 = gtk_button_new_with_label ("Mode 0");
  g_signal_connect (button1, "clicked", G_CALLBACK (mode_button_handler), NULL);

  gtk_grid_attach (GTK_GRID (grid), button1, 0, 0, 10, 10);

  //Load 2nd button
  button2 = gtk_button_new_with_label ("Mode 1");
  g_signal_connect (button2, "clicked", G_CALLBACK (mode_button_handler), NULL);
  gtk_grid_attach (GTK_GRID (grid), button2, 0, 10, 10, 10);

  //Load 3rd button
  button3 = gtk_button_new_with_label ("Mode 2");
  g_signal_connect (button3, "clicked", G_CALLBACK (mode_button_handler), NULL);
  gtk_grid_attach (GTK_GRID (grid), button3, 0, 20, 10, 10);

  //Load 4th button
  button4 = gtk_button_new_with_label ("Mode 3");
  g_signal_connect (button4, "clicked", G_CALLBACK (mode_button_handler), NULL);
  gtk_grid_attach (GTK_GRID (grid), button4, 0, 30, 10, 10);

  //Display the window
  gtk_widget_show_all(window);

}

/*
* Brief - Used to get the third parameter in the packet that needs to be transmitted, i.e set / reset (or On / Off)
*/
static void on_off_window(GtkApplication *app, gpointer user_data)
{

  /* create a new window, and set its title */
  window = gtk_application_window_new (app);
  gtk_window_set_title (GTK_WINDOW (window), "ON-OFF");
  gtk_window_set_default_size(GTK_WINDOW(window), 400, 400);

  gtk_window_set_position(GTK_WINDOW(window), GTK_WIN_POS_CENTER);

  gtk_window_set_resizable(GTK_WINDOW(window), FALSE);

  /* Here we construct the container that is going pack our buttons */
  grid = gtk_grid_new ();

  /* Pack the container in the window */
  gtk_container_add (GTK_CONTAINER (window), grid);

  //Load 1 button
  button1 = gtk_button_new_with_label ("OFF");
  g_signal_connect (button1, "clicked", G_CALLBACK (on_off_button_handler), NULL);

  gtk_grid_attach (GTK_GRID (grid), button1, 0, 0, 10, 10);

  //Load 2 button
  button2 = gtk_button_new_with_label ("ON");
  g_signal_connect (button2, "clicked", G_CALLBACK (on_off_button_handler), NULL);
  gtk_grid_attach (GTK_GRID (grid), button2, 0, 10, 10, 10);

  //Display the window
  gtk_widget_show_all(window);

}

/*
* Brief - Used to get the fourth paramter in the packet that needs to be transmitted, i.e duration
* Is called only when mode is MODE_SET_RESET_DURATION
*/
static void duration_window(GtkApplication *app, gpointer user_data)
{
  window = gtk_application_window_new (app);
  gtk_window_set_title (GTK_WINDOW (window), "Enter Duration");
  gtk_window_set_default_size (GTK_WINDOW (window), 500, 400);

  durationLabel = gtk_label_new("Duration");
  durationEntry = gtk_entry_new();
  gtk_entry_set_placeholder_text(GTK_ENTRY(durationEntry),"Duration");

  durationButton = gtk_button_new_with_label("Next");

  g_signal_connect(durationButton,"clicked",G_CALLBACK(duration_button_handler),NULL);

  GtkWidget *box; box = gtk_box_new(GTK_ORIENTATION_VERTICAL,20);
  gtk_box_pack_start(GTK_BOX(box),durationLabel,FALSE,FALSE,0);
  gtk_box_pack_start(GTK_BOX(box),durationEntry,FALSE,FALSE,0);
  gtk_box_pack_start(GTK_BOX(box),durationButton,FALSE,FALSE,0);

  gtk_container_add(GTK_CONTAINER(window),box);
  gtk_widget_show_all (window);
}

/*
* Brief - Used to get the fourth paramter in the packet that needs to be transmitted, i.e instant of time.
* Is called only when mode is MODE_SET_RESET_INSTANT
*/
static void time_instant_window(GtkApplication *app, gpointer user_data)
{
  window = gtk_application_window_new (app);
  gtk_window_set_title (GTK_WINDOW (window), "Enter Time Instant");
  gtk_window_set_default_size (GTK_WINDOW (window), 500, 400);

  hoursLabel = gtk_label_new("Hours");
  hoursEntry = gtk_entry_new();
  gtk_entry_set_placeholder_text(GTK_ENTRY(hoursEntry),"Hours");

  minutesLabel = gtk_label_new("Minutes");
  minutesEntry = gtk_entry_new();
  gtk_entry_set_placeholder_text(GTK_ENTRY(minutesEntry),"Minutes");

  secondsLabel = gtk_label_new("Seconds");
  secondsEntry = gtk_entry_new();
  gtk_entry_set_placeholder_text(GTK_ENTRY(secondsEntry),"Seconds");

  instantButton = gtk_button_new_with_label("Next");

  g_signal_connect(instantButton,"clicked",G_CALLBACK(time_instant_button_handler),NULL);

  GtkWidget *box; box = gtk_box_new(GTK_ORIENTATION_VERTICAL,20);
  gtk_box_pack_start(GTK_BOX(box),hoursLabel,FALSE,FALSE,0);
  gtk_box_pack_start(GTK_BOX(box),hoursEntry,FALSE,FALSE,0);
  gtk_box_pack_start(GTK_BOX(box),minutesLabel,FALSE,FALSE,0);
  gtk_box_pack_start(GTK_BOX(box),minutesEntry,FALSE,FALSE,0);
  gtk_box_pack_start(GTK_BOX(box),secondsLabel,FALSE,FALSE,0);
  gtk_box_pack_start(GTK_BOX(box),secondsEntry,FALSE,FALSE,0);
  gtk_box_pack_start(GTK_BOX(box),instantButton,FALSE,FALSE,0);

  gtk_container_add(GTK_CONTAINER(window),box);
  gtk_widget_show_all (window);
}

/*
* Refer user_interface.h for description
*/
void get_user_data(char *res, int argc, char **argv)
{
  GtkApplication *app;
  int status;

  //Build and display the window to get Load number
  app = gtk_application_new ("org.gtk.example", G_APPLICATION_FLAGS_NONE);
  g_signal_connect (app, "activate", G_CALLBACK (load_window), NULL);
  status = g_application_run (G_APPLICATION (app), argc, argv);

  //Build and display the window to get Mode
  app = gtk_application_new ("org.gtk.example", G_APPLICATION_FLAGS_NONE);
  g_signal_connect (app, "activate", G_CALLBACK (mode_window), NULL);
  status = g_application_run (G_APPLICATION (app), argc, argv);

  if(mode == MODE_TOGGLE)
  {
      sprintf(res,"%c,%c;",load,mode);
  }

  else if(mode == MODE_ON_OFF_ONLY)
  {
      //Build and display the window to get ON-OFF value
      app = gtk_application_new ("org.gtk.example", G_APPLICATION_FLAGS_NONE);
      g_signal_connect (app, "activate", G_CALLBACK (on_off_window), NULL);
      status = g_application_run (G_APPLICATION (app), argc, argv);

      sprintf(res,"%c,%c,%c;",load,mode,on_off);
  }

  else if(mode == MODE_ON_OFF_DURATION)
  {
    //Build and display the window to get ON-OFF value
    app = gtk_application_new ("org.gtk.example", G_APPLICATION_FLAGS_NONE);
    g_signal_connect (app, "activate", G_CALLBACK (on_off_window), NULL);
    status = g_application_run (G_APPLICATION (app), argc, argv);

    //Build and display the window to get duration in seconds
    app = gtk_application_new ("org.gtk.example", G_APPLICATION_FLAGS_NONE);
    g_signal_connect (app, "activate", G_CALLBACK (duration_window), NULL);
    status = g_application_run (G_APPLICATION (app), argc, argv);

    sprintf(res,"%c,%c,%c,%d;",load,mode,on_off,duration);
  }

  else if(mode == MODE_ON_OFF_INSTANT)
  {
    //Build and display the window to get ON-OFF value
    app = gtk_application_new ("org.gtk.example", G_APPLICATION_FLAGS_NONE);
    g_signal_connect (app, "activate", G_CALLBACK (on_off_window), NULL);
    status = g_application_run (G_APPLICATION (app), argc, argv);

    //Build and display the window to get the instant of time
    app = gtk_application_new ("org.gtk.example", G_APPLICATION_FLAGS_NONE);
    g_signal_connect (app, "activate", G_CALLBACK (time_instant_window), NULL);
    status = g_application_run (G_APPLICATION (app), argc, argv);

    sprintf(res,"%c,%c,%c,%d:%d:%d;",load,mode,on_off,hours,minutes,seconds);
  }


  g_object_unref (app);

  return;
}
