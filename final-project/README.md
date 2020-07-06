
<!-- PROJECT LOGO -->
<br />
<p align="center">
    <img src="static/img/logo.svg" alt="Logo" width="180" height="180">
  </a>

  <h2 align="center">Hospital Management System</h2>
  <h5 align="center"><em>(Using Flask)</em></h5>
</p>



<!-- TABLE OF CONTENTS -->
## Table of Contents

* [About the Project](#about-the-project)
  * [Built With](#built-with)
* [Getting Started](#getting-started)
  * [Prerequisites](#prerequisites)
  * [Installation](#installation)
  * [Usage](#usage)
* [License](#license)
* [Contact](#contact)
* [Acknowledgements](#acknowledgements)



<!-- ABOUT THE PROJECT -->
## About The Project

[![Product Name Screen Shot][product-screenshot]](https://hms-tcs.el.r.appspot.com)

This is a simple hospital management system web application made using python (Flask) as the backend; SQLite as the database; HTML5, CSS3 and Javascript as the frontend.
This application provides ease of access to different stakeholders of the Hospital Management System namely the 'Registration Desk Executive' (responsible to maintain patient records and billing) , 'Pharmacy Executive' (resposible for keeping track of and issuing medicines) and 'Diagnostic Executive' (responsible for conducting diagnosis).
The application is also tailored for each of the stakeholders with a role-based access (such that one stakeholder cannot access other stakeholder's features).
All the 4 CRUD operations of database are covered in the application.

#### Features:

##### 'Registration Desk Executive':
 * View the list of patients in record and can filter patients based on any of their attributes
 * Register a new patient
 * Update the patient details
 * Delete the patient details
 * Bill (automated based on no.of days, tests and medicines issued) and discharge the patient

##### 'Pharmacy Executive':
 * Check the medicines issued to a patient
 * Issue new medicines to a patient

##### 'Diagnostic Executive':
 * Check the tests conducted on a patient
 * Conduct a new test on a patient

In addition to the features, session management and proper validations have been done on WTForms and db queries.

#### Live Demo: https://hms-tcs.el.r.appspot.com

#### Video Demo: https://youtu.be/jYEK13IMGS4



### Built With

* [Bootstrap](https://getbootstrap.com)
* [JQuery](https://jquery.com)
* [Flask](https://palletsprojects.com/p/flask/)



<!-- GETTING STARTED -->
## Getting Started

### Prerequisites

* [python](https://www.python.org/)

### Installation

1. Open hms directory

2a. Create a Virtual Environment (Optional)
```sh
python -m venv .hms
```
2b. Activate the virtual environment
```sh
.hms\Scripts\activate
```
3. Install the requirements and dependancies
```sh
pip install -r requirements.txt
```
4. Run the application
```python
flask run
```
5. View the application on localhost
```
http://localhost:5000/
```


### Usage

#### Login Credentials:

* Admin Executive
```sh
Username: 12345678@A
Password: 12345678@A
```

* Pharmacist
```sh
Username: 12345678@P
Password: 12345678@P
```

* Diagnostic Executive
```sh
Username: 12345678@D
Password: 12345678@D
```

*Note While creating new login credentials please set the ending character with accordance to the role of the stakeholder.*

    * Admin Executive: A
    * Pharmacist: P
    * Diagnostic Executive: D



<!-- LICENSE -->
## License

Distributed under the MIT License. See `LICENSE` for more information.


<!-- CONTACT -->
## Contact

* RamVignesh B. - [![linkedin-shield]](https://linkedin.com/in/ramvigneshb) - ramvignesh.codes@gmail.com


<!-- ACKNOWLEDGEMENTS -->
## Acknowledgements

*Thanks to.....*
* [Bootstrap-Select](https://developer.snapappointments.com/bootstrap-select/)
* [State-City JS](https://github.com/ajayrandhawa/Indian-States-Cities-Database)
* [Choose an Open Source License](https://choosealicense.com)
* [StackOverflow](https://stackoverflow.com)



<!-- MARKDOWN LINKS & IMAGES -->
[linkedin-shield]: https://img.shields.io/badge/-LinkedIn-black.svg?style=flat-square&logo=linkedin&colorB=555
[product-screenshot]: static/img/screenshot.png
