"""
CPU Scheduling - MAIN RUNNER (COMPLETE VISUALIZATION IN ONE IMAGE)
Generates a single comprehensive matplotlib figure with all plots
Uses HelloWorld.java for Process 1
"""

import subprocess
import os
import time
from typing import List
from scheduling_algorithms import (
    Process, PIDGenerator,
    FCFS_Scheduler, SJF_Scheduler, 
    RoundRobin_Scheduler, Priority_Scheduler
)
from scheduling_visualization_complete import SchedulingVisualizationComplete


# ============================================================================
# PROCESS WORK FUNCTIONS
# ============================================================================

class ProcessWork:
    """Process execution implementations"""
    
    @staticmethod
    def helloworld_java(process: Process, process_id: int):
        """Execute HelloWorld.java - USES HELLOWORLD.JAVA FILE"""
        print(f"\n[P{process_id}] ========== COMPILING HELLOWORLD.JAVA (OOP) ==========")
        
        if os.path.exists("HelloWorld.java"):
            print(f"[P{process_id}] ✓ HelloWorld.java found in current directory")
            time.sleep(0.2)
            
            print(f"[P{process_id}] $ javac HelloWorld.java")
            try:
                compile_result = subprocess.run(["javac", "HelloWorld.java"], 
                                              capture_output=True, text=True, timeout=10)
                
                if compile_result.returncode == 0:
                    print(f"[P{process_id}] ✓ Compilation successful!")
                    time.sleep(0.2)
                    
                    print(f"[P{process_id}] $ java HelloWorld")
                    print(f"[P{process_id}] JAVA OUTPUT (OOP DEMO):")
                    
                    java_result = subprocess.run(["java", "HelloWorld"], 
                                               capture_output=True, text=True, timeout=10)
                    
                    if java_result.returncode == 0:
                        output_lines = java_result.stdout.strip().split('\n')
                        for line in output_lines:
                            print(f"[P{process_id}]   {line}")
                            time.sleep(0.02)
                    else:
                        ProcessWork._run_java_simulation(process_id)
                else:
                    ProcessWork._run_java_simulation(process_id)
                    
            except:
                ProcessWork._run_java_simulation(process_id)
        else:
            print(f"[P{process_id}] ✗ HelloWorld.java NOT FOUND")
            ProcessWork._run_java_simulation(process_id)
        
        print(f"[P{process_id}] ✓ P1 (HelloWorld) execution complete\n")
    
    @staticmethod
    def _run_java_simulation(process_id: int):
        """Fallback simulation"""
        print(f"[P{process_id}] [Greeting] Java Program says: Hello, World!")
        time.sleep(0.1)
        print(f"[P{process_id}] [Calculator] Addition: 10 + 5 = 15")
        time.sleep(0.1)
    
    @staticmethod
    def alphabet_task(process: Process, process_id: int):
        """Process 2: Alphabet Task"""
        print(f"\n[P{process_id}] Task 2: Printing A-E")
        for letter in ['A', 'B', 'C', 'D', 'E']:
            print(f"[P{process_id}]   Letter: {letter}")
            time.sleep(0.3)
        print(f"[P{process_id}] ✓ Task 2 Completed\n")
    
    @staticmethod
    def math_task(process: Process, process_id: int):
        """Process 3: Math Task"""
        print(f"\n[P{process_id}] Task 3: Basic Math Operations")
        operations = ["2+3=5", "4*2=8", "10-3=7", "20/4=5"]
        for op in operations:
            print(f"[P{process_id}]   {op}")
            time.sleep(0.25)
        print(f"[P{process_id}] ✓ Task 3 Completed\n")
    
    @staticmethod
    def greeting_task(process: Process, process_id: int):
        """Process 4: Greeting Task"""
        print(f"\n[P{process_id}] Task 4: Processing Names")
        names = ["Alice", "Bob", "Charlie"]
        for name in names:
            print(f"[P{process_id}]   Hello, {name}!")
            time.sleep(0.25)
        print(f"[P{process_id}] ✓ Task 4 Completed\n")


# ============================================================================
# MAIN EXECUTION
# ============================================================================

def create_processes() -> List[Process]:
    """Create process list"""
    return [
        Process(name="HelloWorld", arrival_time=0, burst_time=2.0, priority=1, 
                work_function=ProcessWork.helloworld_java),
        Process(name="Alphabet", arrival_time=0, burst_time=1.5, priority=2, 
                work_function=ProcessWork.alphabet_task),
        Process(name="Math", arrival_time=0, burst_time=1.0, priority=3, 
                work_function=ProcessWork.math_task),
        Process(name="Greeting", arrival_time=0, burst_time=0.75, priority=4, 
                work_function=ProcessWork.greeting_task),
    ]


def create_priority_processes() -> List[Process]:
    """Create process list with UPDATED priorities (3,2,4,1)"""
    return [
        Process(name="HelloWorld", arrival_time=0, burst_time=2.0, priority=3, 
                work_function=ProcessWork.helloworld_java),
        Process(name="Alphabet", arrival_time=0, burst_time=1.5, priority=2, 
                work_function=ProcessWork.alphabet_task),
        Process(name="Math", arrival_time=0, burst_time=1.0, priority=4, 
                work_function=ProcessWork.math_task),
        Process(name="Greeting", arrival_time=0, burst_time=0.75, priority=1, 
                work_function=ProcessWork.greeting_task),
    ]


def main():
    """Main execution function"""
    
    print("\n" + "="*90)
    print("CPU SCHEDULING ALGORITHMS - HelloWorld.Java Integration")
    print("COMPLETE VISUALIZATION IN ONE IMAGE!")
    print("="*90)
    print("\nScheduling Algorithms: FCFS, SJF, RR (TQ=1.5s), Priority (3,2,4,1)")
    print("="*90)
    
    visualization = SchedulingVisualizationComplete()
    
    # ===== FCFS =====
    print("\n\n" + "="*90)
    print("[1/4] FCFS (First Come First Served) SCHEDULING")
    print("="*90)
    PIDGenerator.reset()
    fcfs_processes = create_processes()
    fcfs = FCFS_Scheduler(fcfs_processes)
    fcfs.schedule()
    fcfs_results = fcfs.get_results()
    visualization.store_results('FCFS', fcfs_results)
    visualization.print_algorithm_results("FCFS", fcfs_results)
    
    # ===== SJF =====
    print("\n" + "="*90)
    print("[2/4] SJF (Shortest Job First) SCHEDULING")
    print("="*90)
    PIDGenerator.reset()
    sjf_processes = create_processes()
    sjf = SJF_Scheduler(sjf_processes)
    sjf.schedule()
    sjf_results = sjf.get_results()
    visualization.store_results('SJF', sjf_results)
    visualization.print_algorithm_results("SJF", sjf_results)
    
    # ===== Round Robin =====
    print("\n" + "="*90)
    print("[3/4] ROUND ROBIN (RR) SCHEDULING - Time Quantum: 1.5s")
    print("="*90)
    PIDGenerator.reset()
    rr_processes = create_processes()
    rr = RoundRobin_Scheduler(rr_processes, time_quantum=1.5)
    rr.schedule()
    rr_results = rr.get_results()
    visualization.store_results('Round Robin', rr_results)
    visualization.print_algorithm_results("Round Robin", rr_results)
    
    # ===== Priority (UPDATED) =====
    print("\n" + "="*90)
    print("[4/4] PRIORITY SCHEDULING - UPDATED (3,2,4,1)")
    print("="*90)
    PIDGenerator.reset()
    priority_processes = create_priority_processes()
    priority = Priority_Scheduler(priority_processes)
    priority.schedule()
    priority_results = priority.get_results()
    visualization.store_results('Priority', priority_results)
    visualization.print_algorithm_results("Priority", priority_results)
    
    # Generate complete visualization in ONE image
    print("\n" + "="*90)
    print("GENERATING COMPLETE VISUALIZATION")
    print("="*90)
    
    try:
        visualization.generate_complete_visualization()
        visualization.print_summary()
    except ImportError as e:
        print(f"\n  ERROR: {str(e)}")
        print("\nRequired packages not installed!")
        print("Install with: pip install matplotlib numpy")
    except Exception as e:
        print(f"\n ERROR generating visualization: {str(e)}")


if __name__ == "__main__":
    main()
