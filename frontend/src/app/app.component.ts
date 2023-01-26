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
  public greedySolution: number[] = []
  public greedyDistance?: number;
  public saSolution: number[] = [];
  public saDistance?: number;

  constructor(private getTcpPath: GetTspPathsService, public tspInstance: TspInstanceService) {
  }

  ngOnInit(): void {
    this.tspInstance.points.subscribe(points => {
      this.points = points;
    });
    this.getTcpPath.greedySolution.subscribe((solution: number[]) => {
      this.greedySolution = solution;
    });
    this.getTcpPath.saSolution.subscribe((solution: number[]) => {
      this.saSolution = solution;
    });
    this.getTcpPath.greedyDistance.subscribe((distance: number) => {
      this.greedyDistance = distance;
    });
    this.getTcpPath.saDistance.subscribe((distance: number) => {
      this.saDistance = distance;
    });
  }

}
