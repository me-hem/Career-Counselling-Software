# Career Counselling Software

A console-based interactive career guidance quiz application written in C++ that helps students discover suitable career paths based on their interests and academic level. This project is a comprehensive career counseling tool designed to assist students in making informed career decisions. The application presents interest-based questionnaires prepared for different academic levels (Class 10, Class XII Science, and Class XII Commerce) and provides personalized career recommendations based on user responses.

## Features

### Core Functionality
- **Multi-level Career Assessment**: Separate quiz modules for Class 10, Class XII Science, and Class XII Commerce
- **Interest-based Questionnaires**: Questions designed to identify student interests and aptitudes
- **Real-time Scoring**: Immediate feedback with percentage-based interest calculation
- **Career Recommendations**: Personalized career suggestions based on quiz results
- **Time-limited Questions**: 10-second timer per question to encourage quick, instinctive responses

### User Roles
- **Admin Panel**: 
  - Password-protected access
  - Add new questions and career options
  - Modify existing quiz content
  - View user comments and feedback
- **User Interface**:
  - Take career assessment quizzes
  - Submit feedback and comments
  - View personalized results


## Getting Started

### Prerequisites
- Turbo C++ or any C++ compiler supporting legacy headers
- Windows

### Installation

1. **Clone the repository**
   ```bash
   git clone <repository-url>
   cd Career-Counselling-Software
   ```

2. **Compile the program**
   ```bash
   # Using Turbo C++
   tcc CAREER.CPP
   
   # Or using g++ (may require modifications for modern compilers)
   g++ -o career CAREER.CPP
   ```

3. **Run the application**
   ```bash
   ./career
   ```

## Usage

### For Students (Users)
1. Launch the application
2. Select "USER" from the main menu
3. Choose "Play" to start the quiz
4. Select your academic level (Class 10/XII Science/XII Commerce)
5. Choose your top 2 interests from the provided categories
6. Answer the timed questions (10 seconds each)
7. View your personalized career recommendations
8. Optionally, add comments about your experience

### For Administrators
1. Launch the application
2. Select "ADMIN" from the main menu
3. Enter the admin password
4. Choose from available options:
   - **Play**: Test the quiz functionality
   - **Add**: Create new questions and career options
   - **Modify**: Edit existing quiz content
5. View user comments and feedback

## File Structure

```
Career-Counselling-Software/
├── CAREER.CPP          # Main source code file
├── CAREERX.DAT         # Data file for Class X questions
├── CAREERXIIS.DAT      # Data file for Class XII Science questions
├── CAREERXIIC.DAT      # Data file for Class XII Commerce questions
├── reviews.dat         # User comments and feedback storage
└── README.md           # This file
```

## Technical Details

### Architecture
- **Object-Oriented Design**: Uses multiple classes for different functionalities
- **File-based Storage**: Binary file system for persistent data storage
- **Menu-driven Interface**: Intuitive navigation with keyboard controls

### Key Classes
- `lines`: Handles graphical elements (boxes, lines)
- `menu`: Manages navigation and menu systems
- `quiz`: Core quiz functionality and data management
- `comment`: User feedback system

### Controls
- **Arrow Keys**: Navigate through menu options
- **Enter**: Select menu items
- **ESC**: Exit or go back
- **Number Keys**: Answer quiz questions (1, 2, 3)

