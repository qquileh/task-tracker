CREATE TABLE IF NOT EXISTS students (
    student_id SERIAL PRIMARY KEY,
    first_name VARCHAR(50) NOT NULL,
    last_name VARCHAR(50) NOT NULL
);

CREATE TABLE IF NOT EXISTS tasks (
    task_id SERIAL PRIMARY KEY,
    title VARCHAR(100) NOT NULL,
    created_at TIMESTAMP DEFAULT CURRENT_TIMESTAMP,
    updated_at TIMESTAMP DEFAULT CURRENT_TIMESTAMP,
    status VARCHAR(20) CHECK (status IN ('not completed', 'completed', 'in progress'))
);

CREATE TABLE IF NOT EXISTS student_tasks (
    student_id INT REFERENCES students(student_id) ON DELETE CASCADE,
    task_id INT REFERENCES tasks(task_id) ON DELETE CASCADE,
    PRIMARY KEY (student_id, task_id)
);