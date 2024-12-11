/* MOCK DATA */

-- legion table to track major military units
DROP TABLE IF EXISTS legions;
CREATE TABLE legions (
    legion_id INT PRIMARY KEY,
    legion_number INT NOT NULL,
    legion_name VARCHAR(100),
    founded_year INT,
    disbanded_year INT,
    current_province VARCHAR(100),
    eagle_status VARCHAR(50) CHECK (eagle_status IN ('Intact', 'Lost', 'Recovered')),
    active_strength INT
);

-- cohorts table
DROP TABLE IF EXISTS cohorts;
CREATE TABLE cohorts (
    cohort_id INT PRIMARY KEY,
    legion_id INT REFERENCES legions(legion_id),
    cohort_number INT NOT NULL CHECK (cohort_number BETWEEN 1 AND 10),
    cohort_type VARCHAR(50) CHECK (cohort_type IN ('First Cohort', 'Regular Cohort')),
    commander_name VARCHAR(100),
    strength INT,
    UNIQUE(legion_id, cohort_number)
);

-- soldiers table for individual military personnel
DROP TABLE IF EXISTS soldiers;
CREATE TABLE soldiers (
    soldier_id INT PRIMARY KEY,
    cohort_id INT REFERENCES cohorts(cohort_id),
    first_name VARCHAR(50),
    family_name VARCHAR(100),
    soldier_rank VARCHAR(50),
    origin_province VARCHAR(100),
    enlistment_date DATE,
    discharge_date DATE,
    years_service INT,
    pay_grade VARCHAR(50),
    special_skills TEXT
);

-- equipment table for tracking military gear
DROP TABLE IF EXISTS equipment;
CREATE TABLE equipment (
    equipment_id INT PRIMARY KEY,
    item_name VARCHAR(100),
    category VARCHAR(50) CHECK (category IN ('Weapon', 'Armor', 'Shield', 'Tool', 'Siege Engine')),
    material VARCHAR(50),
    weight_pounds DECIMAL(5,2),
    cost_denarii INT,
    standard_issue BOOLEAN
);

-- battles table for recording military engagements
DROP TABLE IF EXISTS battles;
CREATE TABLE battles (
    battle_id INT PRIMARY KEY,
    battle_name VARCHAR(100),
    location VARCHAR(100),
    battle_date DATE,
    enemy_force VARCHAR(100),
    outcome VARCHAR(50) CHECK (outcome IN ('Victory', 'Defeat', 'Stalemate')),
    roman_casualties INT,
    enemy_casualties INT,
    strategic_value TEXT
);

-- junction table for legions involved in battles
DROP TABLE IF EXISTS legion_battles;
CREATE TABLE legion_battles (
    legion_id INT REFERENCES legions(legion_id),
    battle_id INT REFERENCES battles(battle_id),
    casualties INT,
    performance_rating INT CHECK (performance_rating BETWEEN 1 AND 10),
    PRIMARY KEY (legion_id, battle_id)
);

-- table for tracking soldier equipment assignments
DROP TABLE IF EXISTS soldier_equipment;
CREATE TABLE soldier_equipment (
    soldier_id INT REFERENCES soldiers(soldier_id),
    equipment_id INT REFERENCES equipment(equipment_id),
    issue_date DATE,
    condition_rating INT CHECK (condition_rating BETWEEN 1 AND 5),
    return_date DATE,
    PRIMARY KEY (soldier_id, equipment_id, issue_date)
);

-- table for tracking promotions and transfers
DROP TABLE IF EXISTS service_records;
CREATE TABLE service_records (
    record_id INT PRIMARY KEY,
    soldier_id INT REFERENCES soldiers(soldier_id),
    old_rank VARCHAR(50),
    new_rank VARCHAR(50),
    old_cohort_id INT REFERENCES cohorts(cohort_id),
    new_cohort_id INT REFERENCES cohorts(cohort_id),
    change_date DATE,
    reason TEXT,
    authorized_by VARCHAR(100)
);

-- Insert Legions
INSERT INTO legions (legion_id, legion_number, legion_name, founded_year, disbanded_year, current_province, eagle_status, active_strength) VALUES
(1, 10, 'Legio X Gemina', -27, 456, 'Pannonia', 'Intact', 5500),
(2, 12, 'Legio XII Fulminata', -43, 404, 'Cappadocia', 'Intact', 4800),
(3, 6, 'Legio VI Victrix', 70, 402, 'Britannia', 'Intact', 5200),
(4, 9, 'Legio IX Hispana', -43, 120, 'Britannia', 'Lost', 0);

-- Insert Cohorts
INSERT INTO cohorts (cohort_id, legion_id, cohort_number, cohort_type, commander_name, strength) VALUES
(1, 1, 1, 'First Cohort', 'Marcus Valerius Maximus', 800),
(2, 1, 2, 'Regular Cohort', 'Gaius Julius Agricola', 480),
(3, 1, 3, 'Regular Cohort', 'Lucius Cornelius Felix', 480),
(4, 2, 1, 'First Cohort', 'Titus Flavius Sabinus', 800),
(5, 2, 2, 'Regular Cohort', 'Gnaeus Domitius Corbulo', 480);

-- Insert Soldiers
INSERT INTO soldiers (soldier_id, cohort_id, first_name, family_name, soldier_rank, origin_province, enlistment_date, years_service, pay_grade, special_skills) VALUES
(1, 1, 'Lucius', 'Vorenus', 'Centurion', 'Italia', '67-03-15', 15, 'Senior', 'Siege warfare, Leadership'),
(2, 1, 'Titus', 'Pullo', 'Legionary', 'Italia', '69-06-01', 13, 'Standard', 'Hand-to-hand combat'),
(3, 2, 'Marcus', 'Aquila', 'Optio', 'Gaul', '71-04-10', 11, 'Advanced', 'Cavalry tactics'),
(4, 3, 'Gaius', 'Severus', 'Legionary', 'Hispania', '73-08-22', 9, 'Standard', 'Engineering'),
(5, 4, 'Quintus', 'Magnus', 'Centurion', 'Italia', '65-09-01', 17, 'Senior', 'Artillery operation');

-- Insert Equipment
INSERT INTO equipment (equipment_id, item_name, category, material, weight_pounds, cost_denarii, standard_issue) VALUES
(1, 'Gladius', 'Weapon', 'Iron and Wood', 2.5, 100, true),
(2, 'Lorica Segmentata', 'Armor', 'Iron and Leather', 20.0, 300, true),
(3, 'Scutum', 'Shield', 'Wood and Iron', 22.0, 150, true),
(4, 'Pilum', 'Weapon', 'Iron and Wood', 4.0, 75, true),
(5, 'Pugio', 'Weapon', 'Iron', 1.5, 50, true);

-- Insert Battles
INSERT INTO battles (battle_id, battle_name, location, battle_date, enemy_force, outcome, roman_casualties, enemy_casualties, strategic_value) VALUES
(1, 'Battle of Mons Graupius', 'Caledonia', '83-01-01', 'Caledonians', 'Victory', 364, 10000, 'Secured northern Britannia'),
(2, 'Battle of Tapae', 'Dacia', '88-08-15', 'Dacians', 'Victory', 500, 4000, 'Weakened Dacian resistance'),
(3, 'Battle of Carrhae', 'Parthia', '53-06-09', 'Parthians', 'Defeat', 20000, 100, 'Lost eagle standards');

-- Insert Legion Battles
INSERT INTO legion_battles (legion_id, battle_id, casualties, performance_rating) VALUES
(1, 1, 120, 9),
(2, 1, 244, 8),
(3, 2, 500, 7),
(4, 3, 4500, 3);

-- Insert Soldier Equipment
INSERT INTO soldier_equipment (soldier_id, equipment_id, issue_date, condition_rating, return_date) VALUES
(1, 1, '67-03-15', 4, NULL),
(1, 2, '67-03-15', 3, NULL),
(1, 3, '67-03-15', 4, NULL),
(2, 1, '69-06-01', 3, NULL),
(2, 2, '69-06-01', 4, NULL);

-- Insert Service Records
INSERT INTO service_records (record_id, soldier_id, old_rank, new_rank, old_cohort_id, new_cohort_id, change_date, reason, authorized_by) VALUES
(1, 1, 'Legionary', 'Optio', 2, 1, '72-04-15', 'Exceptional valor in battle', 'Legate Quintus Petillius Cerialis'),
(2, 1, 'Optio', 'Centurion', 1, 1, '75-09-01', 'Years of loyal service', 'Legate Gnaeus Julius Agricola'),
(3, 3, 'Legionary', 'Optio', 2, 2, '76-03-10', 'Demonstrated leadership ability', 'Centurion Marcus Valerius Maximus');