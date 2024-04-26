<h1 align="center">Core Part of Oroneta Project</h1>
<br>
<br>

<p align="center">
  <i>Service and Database for drone registry</i>
</p>

<p align="center">
  <a href="./CONTRIBUTING.md">Contributing</a>
  ·
  <a href="https://github.com/oroneta/core-system">Issues</a>
</p>

<p align="center">
  <a href="https://opensource.org/license/mit">
    <img src="https://img.shields.io/badge/License-ANSCCL-blue.svg" alt="Project License" />
  </a>&nbsp;
  <a>
    <img src="https://img.shields.io/badge/version-S.A-brightgreen" alt="Version" />
  </a>
</p>

<hr>

## Table of Contents

- [Introduction](#introduction)
- [Features](#features)
- [Installation](#installation)
- [Execution](#execution)
- [Testing](#testing)

## Introduction

This repository contains the core part of the Oroneta project. It is a service and database for drone registry. The project saves the information of drones and their owners. Every drone route must be inspected and registered in the system.

## Features

- Register drones
- Register drone routes
- Register registrants

## Installation

To install the project, you need to clone the repository and install the dependencies. You can do this by running the following commands:

```bash
git clone https://github.com/oroneta/core-system.git
cd core-system
```

## Execution

To run the project as prod, you need to run the following command:

```bash
cd docker
docker compose up -d --build
```

If you want to run the project as dev, you need to modify the `docker-compose.yml`

```yml
# Dev
# - ./migration/demo.sql:/docker-entrypoint-initdb.d/demo.sql   --> Uncomment this line
```

And then run the following command:

```bash
cd docker
docker compose up -d --build --force-recreate --remove-orphans
```

## Testing

In the folder you can find the tests for the project. To run the tests, you need to run the following command:

```bash
cd tests
python3 -m pip install -r requirements.txt

# For postgresql database connection tests
python3 -m pytester.py 2

# For services tests
python3 -m pytester.py 1
```

All tests must pass to ensure the correct operation of the project.


## License

This project is lincesed under Creative Common License. See the [LICENSE](./LICENSE) file for more information.

```text
Attribution-NonCommercial-ShareAlike 4.0 International
```

Any of this project's code can be used for non-commercial purposes. Any other use must be approved by the project owner.

All rights reserved to Oroneta Project.
