class Hello
{
    /*CLASS 1 -> demonstation of ENCAPSULATION & CONSTRUCTOR */
    static class Greetings
    {
        private String msg;
        private String sender;
    
    public Greetings (String msg,String sender)
    {
        this.msg=msg;
        this.sender=sender;
    }
    public void display(){
        System.out.println("[greetings] "+sender +" says: "+msg);
    }
    public String getMsg(){
        return msg;
    }
    public String getSender(){
        return sender;
    }
    }

    /*CLASS 2 -> Demonstrates METHOD OVERLOADING */
    static class Calculator{
        private String name;
        public Calculator(String name){
            this.name=name;
        }
        int add(int a ,int b){
            return a+b;
        }
        int add(int a,int b,int c){
            return a+b+c;
        }
        double add (double a,double b){
            return a+b;
        }
        int subtract(int a,int b){
            return a-b;
        }
        int multiply(int a,int b){
            return a*b;
        }
        void displayResult(String op,int result){
            System.out.println("["+name+"] "+op +" = "+result);
        }
    }
    /*CLASS 3-> DEmonstrates STATE MANAGEMENT & LOOPS */
    static class processInfo{
        private int processID;
        private String processname;
        private int[] taskValues;

        processInfo(int pid,String name,int [] values){
            this.processID=pid;
            this.processname=name;
            this.taskValues=values;
        }
        void processValues(){
            System.out.println("[ProcessInfo] Process "+processID +" ("+processname+" ) - Processing values:");
            for(int i=0;i<taskValues.length;i++){
                System.out.println(" [Index "+i+"]: Value = "+taskValues[i]);
            }
            System.out.println("[ProcessInfo] Sum calculation:");
            int sum =0;
            for (int val:taskValues){
                sum+=val;
            }
            System.out.println(" Total Sum: "+sum);
        }
        void displayInfo(){
            System.out.println("[ProcessInfo] PID: "+processID+", Name: "+processname+", Elements: "+taskValues.length);
        }
    }
    /*Class 4-> Demstrates ARRAY OF OBJECTS */
    static class TaskScheduler {
        private String schedulerName;
        private Greetings[] greetings;
        
        // Constructor
        TaskScheduler(String name) {
            this.schedulerName = name;
            this.greetings = new Greetings[3];  // Array of objects
        }
        
        // Method to add greeting
        void addGreeting(int index, Greetings greeting) {
            if (index >= 0 && index < greetings.length) {
                greetings[index] = greeting;
            }
        }
        
        // Method to execute all greetings
        void executeAll() {
            System.out.println("[TaskScheduler] Executing " + schedulerName + ":");
            for (int i = 0; i < greetings.length; i++) {
                if (greetings[i] != null) {
                    greetings[i].display();
                }
            }
        }
    }

    /*MAIN METHOD */
    public static void main(String []args){
        System.out.println("\n"+"-".repeat(60));
        System.out.println("\nGREETING ClASS");
        Greetings greetings1=new Greetings("Hello World", "Java program");
        greetings1.display();
        System.out.println("    [Getter] Message: " + greetings1.getMsg());
        System.out.println("    [Getter] Sender: " + greetings1.getSender());

        System.out.println("\n"+"-".repeat(60));
        System.out.println("\nCALCULATOR CLASS");
        Calculator calc = new Calculator("MathEngine");
        int result1 = calc.add(10, 5);
        calc.displayResult("Addition: 10 + 5", result1);
        int result2 = calc.add(10, 5, 3);
        calc.displayResult("Addition: 10 + 5 + 3", result2);
        double result3 = calc.add(10.5, 5.5);
        System.out.println("[MathEngine] Decimal Add: 10.5 + 5.5 = " + result3);
        calc.displayResult("Subtraction: 10 - 5", calc.subtract(10, 5));
        calc.displayResult("Multiplication: 10 * 5", calc.multiply(10, 5));
        
        System.out.println("\n"+"-".repeat(60));
        System.out.println("\nPROCESSINFO CLASS");
        int[] values = {15, 25, 35, 45};
        processInfo process = new processInfo(101, "DataProcessor", values);
        process.displayInfo();
        process.processValues();

        System.out.println("\n"+"-".repeat(60));
        System.out.println("\nPROCESSING CLASS");
        TaskScheduler sch = new TaskScheduler("CentralSchedular");
        sch.addGreeting(0, new Greetings("First Task Ready", "Scheduler"));
        sch.addGreeting(1, new Greetings("Second Task Ready", "Scheduler"));
        sch.addGreeting(2, new Greetings("Third Task Ready", "Scheduler"));
        sch.executeAll();
    }
}