import {Component, OnInit} from '@angular/core';
import {GetTspPathsService} from "./services/get-tsp-paths.service";
import {TspInstanceService} from "./services/tsp-instance.service";
import {Point} from "@angular/cdk/drag-drop";

@Component({
  selector: 'app-root',
  templateUrl: './app.component.html',
  styleUrls: ['./app.component.css']
})
export class AppComponent implements OnInit {
  public points: Point[] = [];
  public maxX: number = 0;
  public maxY: number = 0;
  public greedySolution: number[] = []
  public saSolution: number[] = [];

  constructor(private getTcpPath: GetTspPathsService, public tspInstance: TspInstanceService) {
  }

  ngOnInit(): void {
    this.tspInstance.points.subscribe(points => {
      this.points = points;
    });
    this.tspInstance.maxX.subscribe((maxX: number) => {
      this.maxX = maxX
    });
    this.tspInstance.maxY.subscribe((maxY: number) => {
        this.maxY = maxY;
      }
    );
    this.getTcpPath.greedySolution.subscribe((solution: number[]) => {
      this.greedySolution = solution;
    });
    this.getTcpPath.saSolution.subscribe((solution: number[]) => {
      this.saSolution = solution;
    });
  }


}
