"""
CPU Scheduling Algorithms - CORE MODULE
Single source of truth for all scheduling algorithms
No visualization code - just pure algorithms
"""

import threading
from collections import deque
from dataclasses import dataclass, field
from typing import List, Callable
import statistics


# ============================================================================
# AUTO PID GENERATION
# ============================================================================

class PIDGenerator:
    """Automatic Process ID generator"""
    _next_pid = 1
    _lock = threading.Lock()
    
    @classmethod
    def get_next_pid(cls):
        """Generate next available PID"""
        with cls._lock:
            pid = cls._next_pid
            cls._next_pid += 1
            return pid
    
    @classmethod
    def reset(cls):
        """Reset PID counter"""
        with cls._lock:
            cls._next_pid = 1


# ============================================================================
# PROCESS CLASS
# ============================================================================

@dataclass
class Process:
    """Represents a process with execution requirements"""
    name: str
    arrival_time: int = 0
    burst_time: int = 0
    priority: int = 0
    work_function: Callable = None
    pid: int = field(default_factory=PIDGenerator.get_next_pid)
    lock: threading.Lock = field(default_factory=threading.Lock)
    execution_start_time: float = 0.0
    execution_end_time: float = 0.0
    
    def __repr__(self):
        return f"P{self.pid}"


# ============================================================================
# SCHEDULER BASE CLASS
# ============================================================================

class Scheduler:
    """Base scheduler class with metrics calculation"""
    
    def __init__(self, processes: List[Process]):
        self.processes = sorted(processes, key=lambda p: p.arrival_time)
        self.completion_times = {}
        self.turnaround_times = {}
        self.waiting_times = {}
        self.gantt_chart = []
        self.scheduler_lock = threading.Lock()
    
    def calculate_metrics(self):
        """Calculate metrics based on execution times"""
        for process in self.processes:
            ct = self.completion_times[process.pid]
            self.turnaround_times[process.pid] = ct - process.arrival_time
            self.waiting_times[process.pid] = self.turnaround_times[process.pid] - process.burst_time
    
    def get_results(self):
        """Get scheduling results as dictionary"""
        return {
            'completion_times': self.completion_times.copy(),
            'turnaround_times': self.turnaround_times.copy(),
            'waiting_times': self.waiting_times.copy(),
            'gantt_chart': self.gantt_chart.copy(),
            'processes': self.processes
        }


# ============================================================================
# SCHEDULING ALGORITHMS
# ============================================================================

class FCFS_Scheduler(Scheduler):
    """First Come First Served Scheduling"""
    
    def schedule(self):
        """Execute FCFS scheduling"""
        queue = deque(self.processes)
        current_time = 0
        
        while queue:
            process = queue.popleft()
            
            if current_time < process.arrival_time:
                current_time = process.arrival_time
            
            if process.work_function:
                process.work_function(process, process.pid)
            
            current_time += process.burst_time
            self.completion_times[process.pid] = current_time
            self.gantt_chart.append((process.pid, process.burst_time))
        
        self.calculate_metrics()


class SJF_Scheduler(Scheduler):
    """Shortest Job First Scheduling"""
    
    def schedule(self):
        """Execute SJF scheduling"""
        remaining_processes = list(self.processes)
        current_time = 0
        
        while remaining_processes:
            available = [p for p in remaining_processes if p.arrival_time <= current_time]
            
            if not available:
                current_time = min(p.arrival_time for p in remaining_processes)
                available = [p for p in remaining_processes if p.arrival_time <= current_time]
            
            process = min(available, key=lambda p: p.burst_time)
            remaining_processes.remove(process)
            
            if process.work_function:
                process.work_function(process, process.pid)
            
            current_time += process.burst_time
            self.completion_times[process.pid] = current_time
            self.gantt_chart.append((process.pid, process.burst_time))
        
        self.calculate_metrics()


class RoundRobin_Scheduler(Scheduler):
    """Round Robin Scheduling"""
    
    def __init__(self, processes: List[Process], time_quantum: float = 1.5):
        super().__init__(processes)
        self.time_quantum = time_quantum
    
    def schedule(self):
        """Execute RR scheduling"""
        queue = deque(self.processes)
        current_time = 0
        process_remaining = {p.pid: p.burst_time for p in self.processes}
        
        while queue:
            process = queue.popleft()
            
            execution_time = min(self.time_quantum, process_remaining[process.pid])
            
            if process.work_function:
                process.work_function(process, process.pid)
            
            current_time += execution_time
            process_remaining[process.pid] -= execution_time
            
            if process_remaining[process.pid] > 0:
                queue.append(process)
            else:
                self.completion_times[process.pid] = current_time
            
            self.gantt_chart.append((process.pid, execution_time))
        
        self.calculate_metrics()


class Priority_Scheduler(Scheduler):
    """Priority Based Scheduling"""
    
    def schedule(self):
        """Execute Priority scheduling"""
        remaining_processes = list(self.processes)
        current_time = 0
        
        while remaining_processes:
            available = [p for p in remaining_processes if p.arrival_time <= current_time]
            
            if not available:
                current_time = min(p.arrival_time for p in remaining_processes)
                available = [p for p in remaining_processes if p.arrival_time <= current_time]
            
            process = min(available, key=lambda p: p.priority)
            remaining_processes.remove(process)
            
            if process.work_function:
                process.work_function(process, process.pid)
            
            current_time += process.burst_time
            self.completion_times[process.pid] = current_time
            self.gantt_chart.append((process.pid, process.burst_time))
        
        self.calculate_metrics()


# ============================================================================
# UTILITY FUNCTIONS
# ============================================================================

def calculate_avg_metrics(results):
    """Calculate average metrics from results"""
    if not results['turnaround_times']:
        return 0, 0, 0
    
    avg_tat = statistics.mean(results['turnaround_times'].values())
    avg_wt = statistics.mean(results['waiting_times'].values())
    total_time = max(results['completion_times'].values())
    
    return avg_tat, avg_wt, total_time
