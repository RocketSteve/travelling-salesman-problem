import {Injectable} from '@angular/core';
import {Point} from "../components/graph/point";
import {Subject} from "rxjs";

@Injectable({
  providedIn: 'root'
})
export class TspInstanceService {

  public points: Subject<Point[]> = new Subject<Point[]>();
  public maxX: Subject<number> = new Subject<number>();
  public maxY: Subject<number> = new Subject<number>();

  constructor() {
  }

  getTspInstance(instance: string) {
    const lines = instance.split("\n");
    const numberOfPoints = parseInt(lines[0]);
    let maxX = 0, maxY = 0;
    if (numberOfPoints > 0) {
      const points: Point[] = [];
      for (let i = 1; i < lines.length; i++) {
        if (lines[i].length === 0) continue;
        const line = lines[i].split(" ");
        if (parseInt(line[0]) > maxX) maxX = parseInt(line[0]);
        if (parseInt(line[1]) > maxY) maxY = parseInt(line[1]);
        points.push({x: parseInt(line[0]), y: parseInt(line[1])});
      }
      this.maxY.next(maxY);
      this.maxX.next(maxX);
      this.points.next(points);
    }
  }
}
